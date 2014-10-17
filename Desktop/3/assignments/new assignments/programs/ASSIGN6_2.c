
/*ARYA KUMAR 09/CSE/44
NAVEEN KUMAR CHAUBEY 09/CSE/46
PRAVEEN KUMAR VERMA 09/CSE/48
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define P(s) semop(s, &pop, 1)
#define V(s) semop(s, &vop, 1)
main()
{
        int *a,pid1,pid2;
        int i,j, count = 10, status;
        int semid1, semid2,shmid3 ;
		shmid3 = shmget(IPC_PRIVATE, 1*sizeof(int), 0777|IPC_CREAT);
	    a= (int *) shmat(shmid3, 0, 0);
	    a[0]=0;
        struct sembuf pop, vop ;
        semid1 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
        semid2 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
        semctl(semid1, 0, SETVAL, 0);
        semctl(semid2, 0, SETVAL, 1);
        pop.sem_num = vop.sem_num = 0;
        pop.sem_flg = vop.sem_flg = 0;
        pop.sem_op = -1 ; vop.sem_op = 1 ;
        if ((pid1=fork()) == 0) {
          while (count) {
                 P(semid1);
                 a[0]--;
                 printf(" \t\t\t\t\Child1  %d\n",a[0]);
                 V(semid2);
                 count--;
              }
          }
       if ((pid2=fork()) == 0) {
         while (count) {
                 //sleep(1);
                 P(semid2);
              	a[0]++;
                 printf("child2  %d\n", a[0]);
                 V(semid1);
                 count--;
               }
	     semctl(semid1, 0, IPC_RMID, 0);
             semctl(semid2, 0, IPC_RMID, 0);
        }
wait(&status);
return 0;
}

