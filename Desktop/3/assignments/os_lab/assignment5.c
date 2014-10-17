#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define P(s) semop(s, &pop, 1) 
#define V(s) semop(s, &vop, 1) 
main()
{
int *a, *b,in=0,out=0;
int i,j, count = 10, status;
int semid1, semid2,shmid ;
struct sembuf pop, vop ;
semid1 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
semid2 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
shmid = shmget(IPC_PRIVATE, 10*sizeof(int), 0777|IPC_CREAT);
semctl(semid1, 0, SETVAL, 0);
semctl(semid2, 0, SETVAL, 1);
pop.sem_num = vop.sem_num = 0;
pop.sem_flg = vop.sem_flg = 0;
pop.sem_op = -1 ; vop.sem_op = 1 ;
if (fork() == 0) {
/* Child Process:: Consumer */
b = (int *) shmat(shmid, 0, 0);
while (count) {
P(semid1);
sleep(1);
printf("\t\t\t\t Consumer reads %d\n",b[out]);
out=out+1;
V(semid2);
count--;
}
}
else {
/* Parent Process:: Producer */
int data=0;
a = (int *) shmat(shmid, 0, 0);
while (count) {
sleep(1);
P(semid2);
//printf("enter the data to write : ");
//scanf("%d",&data);
printf("Producer writes %d\n", data);
a[in]=data;
data++;
in=in+1;
V(semid1);
count--;
}

wait(&status);
semctl(semid1, 0, IPC_RMID, 0);
semctl(semid2, 0, IPC_RMID, 0);
shmctl(shmid, IPC_RMID, 0);

}
}


