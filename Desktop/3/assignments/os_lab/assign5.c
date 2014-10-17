/* ROHIT KUMAR 09/CSE/67
   RAHUL KUMAR 09/CSE/68
   SUMEET KUMAR JHA 09/CSE/88
*/
	
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#define P(s) semop(s, &pop, 1)
#define V(s) semop(s, &vop, 1)

int main(){
       
  
	int shmid,status,mutexc,mutexp,nrfull,nrempty;
	int *SUM, *b;
	int *buffer;
	int in = 0, out = 0;
	int sum = 0;
	int m,n;
	printf("Enter no. of producers\n");
	scanf("%d",&m);
	printf("Enter no. of consumer\n");
	scanf("%d",&n);
       	int count = 50 * m;
	        struct sembuf pop, vop ;
        mutexp = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
        mutexc = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
	nrfull = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
        nrempty = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
        semctl(mutexp, 0, SETVAL, 1);
        semctl(mutexc, 0, SETVAL, 1);
	semctl(nrfull, 0, SETVAL, 0);
        semctl(nrempty, 0, SETVAL, 20);
        pop.sem_num = vop.sem_num = 0;
        pop.sem_flg = vop.sem_flg = 0;
        pop.sem_op = -1 ; vop.sem_op = 1 ;
	shmid = shmget(IPC_PRIVATE, sizeof(int), 0777|IPC_CREAT);
	shmid = shmget(IPC_PRIVATE, 20 * sizeof(int), 0777|IPC_CREAT);
	if(fork() == 0){
		buffer = (int *) shmat(shmid, 0, 0);
		while(count){
			count--;
			P(mutexc);
			P(nrfull);
			int val = buffer[out];
			printf("\nConsuming.. %d\n",buffer[out]);
			out = (out+1)%20;
			V(nrempty);
			V(mutexp);
			sum += val;
		}	
		b = (int *) shmat(shmid, 0, 0);
		b[0] = sum;
		shmdt(b);
		shmdt(buffer);
	}
	else if(fork() > 0){
		int data = 0;
		buffer = (int *) shmat(shmid, 0, 0);
		while(count){
			if(data == 50)
				data = 0;
			count--;
			data++;
			P(mutexp);
			P(nrempty);
			buffer[in] = data;
			printf("\nProducing.. %d\n",buffer[in]);
			in = (in + 1)%20;
			V(nrfull);
			V(mutexc);
		}
		SUM = (int *) shmat(shmid, 0, 0);
		wait(&status);
		printf("\nSUM = %d\n", SUM[0]);
		shmdt(SUM);
		shmctl(shmid, IPC_RMID, 0);
	}
	return 0;
}
