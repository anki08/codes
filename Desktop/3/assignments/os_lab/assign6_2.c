/*  ROHIT KUMAR 09/CSE/67
    RAHUL KUMAR 09/CSE/68
    SUMEET KUMAR JHA 09/CSE/88
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#define P(s) semop(s, &pop, 1)
#define V(s) semop(s, &vop, 1)
main()
{
int shmid,status,semid1,semid2;
int *a, *b;
int i;
shmid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT);
  struct sembuf pop, vop ;
        semid1 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
        semid2 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
        semctl(semid1, 0, SETVAL, 0);
        semctl(semid2, 0, SETVAL, 1);
        pop.sem_num = vop.sem_num = 0;
        pop.sem_flg = vop.sem_flg = 0;
        pop.sem_op = -1 ; vop.sem_op = 1 ;
if (fork() == 0) {
b = (int *) shmat(shmid, 0, 0);
for( i=0; i< 10; i++) {
P(semid1);
sleep(1);
printf("\t\t\t Child reads: %d,%d\n",b[0],b[1]);
V(semid2);
}
shmdt(b);
}
else {
a = (int *) shmat(shmid, 0, 0);
a[0] = 0; a[1] = 1;
for( i=0; i< 10; i++) {
P(semid2);
sleep(1);
a[0] = a[0] + a[1];
a[1] = a[0] + a[1];
printf("Parent writes: %d,%d\n",a[0],a[1]);
V(semid1);
}
wait(&status);
shmdt(a);
shmctl(shmid, IPC_RMID, 0);
  semctl(semid1, 0, IPC_RMID, 0);
             semctl(semid2, 0, IPC_RMID, 0);
}
}
 
