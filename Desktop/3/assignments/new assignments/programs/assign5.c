#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/shm.h>

#define MAX 20
#define P(s) semop(s, &pop, 1)
#define V(s) semop(s, &vop, 1)

int shmid1,shmid2,shmid3,shmid4;
int *shmq,*SUM,*q,*no_of_read,m,n;
int semid1, semid2,semid3,semid4;
struct sembuf block,allow,pop,vop;

int producer(int p);
int consumer(int c);
int delete();
int insert(int);

int main()
{
 int i;
 shmid1=shmget(1234,20*sizeof(int),0777|IPC_CREAT);
 shmq=(int*)shmat(shmid1,0,0); for(i=0;i<MAX;i++)shmq[i]=0;
 
 shmid2=shmget(1235,1*sizeof(int),0777|IPC_CREAT);
 SUM=(int*)shmat(shmid2,0,0); *SUM=0;
 
 shmid3=shmget(1236,2*sizeof(int),0777|IPC_CREAT);
 q=(int*)shmat(shmid3,0,0); q[0]=q[1]=-1;
 
 shmid4=shmget(1237,sizeof(int),0777|IPC_CREAT);
 no_of_read=(int*)shmat(shmid4,0,0); *no_of_read=0;
 
 printf("\nENTER THE NUMBER OF PRODUCERS:");scanf("%d",&m);
 printf("\nENTER THE NUMBER OF CONSUMERS:");scanf("%d",&n);

	
 semid1 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
 semid2 = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
 semid3 = semget(IPC_PRIVATE, m, 0777|IPC_CREAT);
 semid4 = semget(IPC_PRIVATE, n, 0777|IPC_CREAT);
	
 semctl(semid1, 0, SETVAL, 0);semctl(semid2, 0, SETVAL, 1);
 semctl(semid3, 0, SETVAL, 1);semctl(semid4, 0, SETVAL, 1);
 for(i=1;i<m;i++)semctl(semid3, i, SETVAL, 0); 
 for(i=1;i<n;i++)semctl(semid4, i, SETVAL, 0);

 pop.sem_num = vop.sem_num = 0;
 pop.sem_flg = vop.sem_flg = 0;
 pop.sem_op = -1 ; 
 vop.sem_op = 1 ;

//Producers
 for(i=0;i<m;i++)
 { if(fork()==0)
  {
   producer(i);
  } 
 }
//Consumers
 for(i=0;i<n;i++)
 {
  if(fork()==0)
  {
   consumer(i);
  }
 }
 while(*no_of_read<(m*50)); 
 printf("\n........................................................................\n");
 printf("\n\t\t Producers:%d Consumers:%d SUM :%d\n",m,n,*SUM);

 semctl(semid1, 0, IPC_RMID, 0);
 semctl(semid2, 0, IPC_RMID, 0);
 semctl(semid3, 0, IPC_RMID, 0);
 semctl(semid4, 0, IPC_RMID, 0);
 shmdt(shmq); shmdt(SUM); shmdt(q); shmdt(no_of_read);
 shmctl(shmid1,IPC_RMID,0); shmctl(shmid2,IPC_RMID,0);
 shmctl(shmid3,IPC_RMID,0); shmctl(shmid4,IPC_RMID,0);
}

int block_no(int b,int s )
{
 block.sem_num=b;
 block.sem_flg=0;
 block.sem_op=-1;
 semop(s, &block, 1);
 return 1;
}

int allow_no(int a,int s)
{
 allow.sem_num=a;
 allow.sem_flg=0;
 allow.sem_op=1;
 semop(s, &allow, 1);
 return 1;
}

int insert(int val)
{
 if((q[0]==0 && q[1]==MAX-1) || (q[1]+1==q[0]))
 { return 0;}
else
 {
  if(q[1]==MAX-1)
   q[1]=0;
  else
   q[1]++;
   shmq[q[1]]=val;
 }
 if(q[0]==-1)
   q[0]=0;
 return 1;
}

int delete()
{
 int k;
 if(q[0]==-1)
 { return 0;}
else
 {
  k=shmq[q[0]];
  if(q[0]==q[1])
    q[0]=q[1]=-1;
  else
   {
    if(q[0]==MAX-1)
     q[0]=0;
    else
     q[0]++;
   }
 }
 return k;
}


int consumer(int c)
{
 int ele;
 do
 {
  block_no(c,semid4);
  P(semid1);
  while(1)
  {
   ele=delete();
   if(ele>0)
   {*SUM=*SUM+ele;
    *no_of_read=*no_of_read+1;}
   else
   {V(semid2);
    allow_no((c+1)%n,semid4);
     break;}
  }               
 }while(*no_of_read<(m*50));
 exit(56);
}
int producer(int p)
{
int i=1;
do{
   do
   {
    block_no(p,semid3);
    P(semid2);
    while(1)
      {
       if(i<51&&insert(i))
         i++;
       else   
         break;
      }
    V(semid1);
     allow_no((p+1)%m,semid3);    

   }while(i<51);
  }while(*no_of_read<(m*50));
  exit(57);
}
