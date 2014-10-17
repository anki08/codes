#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 20
#define PRODUCTS 50

#define P(s) semop(s, &pop, 1)

#define V(s) semop(s, &vop, 1)

struct sembuf pop, vop ;

int to_power(int base, int power)
{
	int i = 0, p = 1;
	for( i = 1; i <= power; i++)
	{
		p = p * base;
	}
	return p;
}

void initialize(int *buf, int val)		//Initialize buffer values
{
	int i;
	for( i = 0; i < BUFFSIZE; i++)
	{
		buf[i] = val;
	}
}

int isfull(int *buf)				//Check if buffer is full
{
	int i;
	for( i = 0; i < BUFFSIZE; i++)
	{
		if( buf[i] == 0 )
		{
			return 0;
		}
	}
	return 1;
}

int isempty(int *buf)				//Check if buffer is empty
{
	int i;
	for( i = 0; i < BUFFSIZE; i++)
	{
		if( buf[i] != 0 )
		{
			return 0;
		}
	}
	return 1;
}


void producer(int *buf, int *index, int *remain, int semid1, int semid2)		//Producer function
{
	printf("\n Producer at index %d:", *index);
	int i, j;
	for( i = 0; i < PRODUCTS; i++ )
	{
		while( isfull(buf) )			;
		{
			usleep(2000);
		}
		for( j = 0; j < BUFFSIZE; j++)
		{
			if( buf[j] == 0)
			{
				P(semid1);
				buf[j] = i + 1;
				V(semid2);
				break;
			}
		}
	}
	*remain = *remain - 1;
	printf("\nProduced\n");
}


void consumer(int *buf, int *sum, int *index, int *remain, int semid1, int semid2)		//Consumer function
{
	printf("\nConsumer at index %d:", *index);
	int j;
	for( ; ; )
	{
		while( isempty(buf) && ( *remain != 0 )  )
		{
			usleep(2000);
		}
		P(semid2);
		for( j = 0; j < BUFFSIZE; j++ )
		{
			if( buf[j] != 0 )
			{
				*sum += buf[j];
				buf[j] = 0;
			}
		}
		V(semid1);
		if( *remain == 0 )
		{
			printf("\nConsumed\n");
			return;
		}
	}
}

int main(void)
{
	int shmidbuf, shmidsum, shmidforked, shmidpro_remaining, status;
	int *buf, *sum, *forked, *remaining_pro;
	int prod, cons, i, j;
	pid_t *pid, orig_parent;

	int semid1, semid2;

	printf("\nEnter the no. of producers, m:");
	scanf("%d", &prod);
	printf("\nEnter the no. of consumers, n:");
	scanf("%d", &cons);

	pid =( pid_t *)malloc( (prod + cons)*sizeof(pid_t));

	shmidbuf = shmget(IPC_PRIVATE, BUFFSIZE*sizeof(int), 0777|IPC_CREAT);
	buf = (int*)shmat(shmidbuf, 0, 0);
	initialize(buf, 0);

	shmidsum = shmget(IPC_PRIVATE, 1*sizeof(int), 0777|IPC_CREAT);
	sum = (int*)shmat(shmidsum, 0, 0);
	*sum = 0;

	shmidforked = shmget(IPC_PRIVATE, 1*sizeof(int), 0777|IPC_CREAT);
	forked = (int*)shmat(shmidforked, 0, 0);
	*forked = 0;

	shmidpro_remaining = shmget(IPC_PRIVATE, 1*sizeof(int), 0777|IPC_CREAT);
	remaining_pro = (int*)shmat(shmidpro_remaining, 0, 0);
	*remaining_pro = prod;

	semid1 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
	semid2 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);

	semctl(semid1, 0, SETVAL, 0);
	semctl(semid2, 0, SETVAL, 1);

	pop.sem_num = vop.sem_num = 0;
	pop.sem_flg = vop.sem_flg = 0;
	pop.sem_op = -1 ; vop.sem_op = 1 ;

	orig_parent = getpid();

	for( i = 0; i < prod + cons; i++)
	{
		pid[i] = fork();
	}
	for( i = 0; i < prod + cons; i++ )
	{
		if( pid[i] == 0)
		{
			char flag = 't';
			for( j = 0; j < prod + cons; j++ )
			{
				if( (i != j) && (pid[j] == 0) )
				{
					flag = 'f';
				}
			}
			if( flag == 't' )
			{
				*forked = *forked + 1;
				if( *forked <= prod )
				{
					printf("\nStarting producer at index %d\n", *forked);
					producer(buf, forked, remaining_pro, semid1, semid2);
					printf("\nExiting producer\n");
					shmdt(buf);
					shmdt(sum);
					shmdt(forked);
					shmdt(remaining_pro);
					return 0;
				}
				else
				{
					printf("\nStarting consumer at index %d\n", *forked);
					consumer(buf, sum, forked, remaining_pro, semid1, semid2);
					printf("\nExiting consumer\n");
					shmdt(buf);
					shmdt(sum);
					shmdt(forked);
					shmdt(remaining_pro);
					return 0;
				}
			}
		}
	}
	if(getppid() != orig_parent && getpid() != orig_parent)
	{
		shmdt(buf);
		shmdt(sum);
		shmdt(forked);
		shmdt(remaining_pro);
		return 0;
	}
	for( i = 0; i < to_power(2, prod + cons) - 1; i++ )
	{
		wait(&status);
	}

	printf("\nFinal_Sum = %d\n", *sum);
	shmdt(buf);
	shmdt(sum);
	shmdt(forked);
	shmdt(remaining_pro);
	shmctl(shmidbuf, IPC_RMID, 0);
	shmctl(shmidsum, IPC_RMID, 0);
	shmctl(shmidforked, IPC_RMID, 0);
	shmctl(shmidpro_remaining, IPC_RMID, 0);

	semctl(semid1, 0, IPC_RMID, 0);
	semctl(semid2, 0, IPC_RMID, 0);

	return 0;
}
