/*ASSIGNMENT 6 part 2
 
STUDENTS: JASNEET SINGH BHATTI-09/CSE/51
          ABHISHEK KUMAR LABH-09/CSE/52
          INDRA MANI-09/CSE/81
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>

#define P(s) semop(s, &pop, 1) 

#define V(s) semop(s, &vop, 1) 

int main(void)
{
	signed int *X;
	pid_t pid1, pid2;
	int shmid, i, status;

	struct sembuf pop, vop ;

	int semid1, semid2;

	semid1 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
	semid2 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);

	semctl(semid1, 0, SETVAL, 0);
	semctl(semid2, 0, SETVAL, 1);

	pop.sem_num = vop.sem_num = 0;
	pop.sem_flg = vop.sem_flg = 0;
	pop.sem_op = -1 ; vop.sem_op = 1 ;

	shmid = shmget(IPC_PRIVATE, 1*sizeof(signed int), 0777|IPC_CREAT);
	X = (signed int *)shmat(shmid, 0, 0);
	*X = 0;
	
	pid1 = fork();
	pid2 = fork();

	if(pid1 == 0 && pid2 != 0)
	{
		P(semid1);
		for( i = 0; i < 10; i++)
		{
			*X += 1;
			if( i == 4 )
				sleep(1);
			printf("\nIncrementing");
		}
		shmdt(X);
		V(semid2);
		return 0;
	}
	if(pid2 == 0 && pid1 != 0)
	{
		P(semid2);
		for( i = 0; i < 10; i++)
		{
			*X -= 1;
			printf("\nDecrementing");
		}
		shmdt(X);
		V(semid1);
		return 0;
	}
	if(pid1 == 0 && pid2 == 0)
		return 0;
	
	for( i = 0; i < 3; i++)
		wait(&status);
	
	printf("\nValue of X = %d\n", *X);

	shmdt(X);
	shmctl(shmid, IPC_RMID, 0);	
	
	semctl(semid1, 0, IPC_RMID, 0);
	semctl(semid2, 0, IPC_RMID, 0);

	return 0;
}
