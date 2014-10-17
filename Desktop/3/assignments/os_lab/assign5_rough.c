#include<stdio.h>

#include<sys/types.h>

#include<sys/sem.h>

#include<stdlib.h>

#include<sys/shm.h>

#include<errno.h>

#include<sys/ipc.h>

void sem_acq(int);

void sem_rel(int);

int main()

{          int mutex,empty,full,shmid, n;

pid_t ret;

int in=-1,out=-1;

char *buffer;

char c[2];

printf(“\nProducer Consumer Problem using Semaphore\n”);

printf(“\nEnter the size for buffer:”);

scanf(“%d”, &n);

if((mutex=semget(IPC_PRIVATE,1,0666|IPC_CREAT))==-1) {

perror(“\nFailed to create semaphore.”);

exit(0);

}

if((semctl(mutex,0,SETVAL,1))==-1) {

perror(“\nFailed to set value for the semaphore.”);

exit(0);

}

if((empty=semget(IPC_PRIVATE,1,0666|IPC_CREAT))==-1) {

perror(“\nFailed to create semaphore.”);

exit(0);

}

if((semctl(empty,0,SETVAL,n))==-1) {

perror(“\nFailed to set value for semaphore.”);

exit(0);

}

if((full=semget(IPC_PRIVATE,1,0666|IPC_CREAT))==-1) {

perror(“\nFailed to create semaphore.”);

exit(0);

}

if((semctl(full,0,SETVAL,0))==-1) {

perror(“\nFailed to set value for the semaphore.”);

exit(0);

}

if((shmid=shmget(IPC_PRIVATE,n*sizeof(char),0666|IPC_CREAT))==-1) {

perror(“\nFailed to allocate shared memory.”);

exit(0);

}

buffer=(char *)shmat(shmid,(const void *)0,0);

ret=fork();

while(1) {

if(ret==0) //Producer

{

sem_acq(empty);

printf(“\nItem produced: “);

scanf(“%s”,c);

sem_acq(mutex);

in = (in+1)%n;

buffer[in]=c[0];

sem_rel(mutex);

sem_rel(full);

}

else if(ret>0) //Consumer

{

sleep(5);

sem_acq(full);

sem_acq(mutex);

out = (out+1)%n;

c[0]=buffer[out];

printf(“\nItem consumed: %c”,c[0]);

sem_rel(mutex);

sem_rel(empty);

}

}

}

void sem_acq(int semid)

{

struct sembuf sb;

sb.sem_num=0;

sb.sem_op=1;

sb.sem_flg=0;

if((semop(semid,&sb,1))==-1)    {

perror(“\nFailed to acquire semaphore.”);

exit(0);

}

}

void sem_rel(int semid)

{

struct sembuf sb;

sb.sem_num=0;

sb.sem_op=1;

sb.sem_flg=0;

if((semop(semid,&sb,1))==-1)    {

perror(“\nFailed to release semaphore.”);

exit(0);

}

}
