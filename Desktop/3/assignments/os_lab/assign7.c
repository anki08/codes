/*  ROHIT KUMAR 09/CSE/67
    RAHUL KUMAR 09/CSE/68
    SUMEET KUMAR JHA 09/CSE/88
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int A[4][4];
int B[4][4];
int C[4][4];

void *Add()
{
   
   int i,j;
   
   for(i=0;i<4;i++)
	{
	 for(j=0;j<4;j++)
	 	C[i][j]=B[i][j]+A[i][j];
	}
   printf("THE ADDED MATRIX\n");
      for(i=0;i<4;i++)
	{
	 for(j=0;j<4;j++)
	 printf("   %d",C[i][j]);
	 printf("\n");
	}
   pthread_exit(NULL);
}

void *Sub()
{
   
   int i,j;
   
   for(i=0;i<4;i++)
	{
	 for(j=0;j<4;j++)
	 	C[i][j]=B[i][j]-A[i][j];
	}
   printf("THE SUBSTRACTED MATRIX\n");
      for(i=0;i<4;i++)
	{
	 for(j=0;j<4;j++)
	 printf("   %d",C[i][j]);
	 printf("\n");
	}
   pthread_exit(NULL);
}

void *Mul()
{
	int i,j,k;
   
   	for(i=0;i<4;i++)
	{
	 
	 for(j=0;j<4;j++)
	 {
	  C[i][j]=0;
	  for(k=0;k<4;k++)
	  	{
	 	C[i][j]+=A[i][k]*B[k][j];
	 	}
	 }
	}
  	 printf("THE MULTIPLIED MATRIX\n");
         for(i=0;i<4;i++)
	 {
	 for(j=0;j<4;j++)
	 printf("   %d",C[i][j]);
	 printf("\n");
	 }
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   
   pthread_t t1,t2,t3;
   int rc1,rc2,rc3;
   int i,j,ch;
   printf("ENtER MATRIX A      ");
   for(i=0;i<4;i++)
	{
	 for(j=0;j<4;j++)
	 scanf("%d", &A[i][j]);
	}
  
  printf("ENtER MATRIX B       ");
    for(i=0;i<4;i++)
	{
	 for(j=0;j<4;j++)
	 scanf("%d",&B[i][j]);
	}
   do
   {
   printf("Select thread 1 for Addition, 2 for SSubstraction and 3 for Multi[lication 0 to Exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
   case 1:
   printf("In main: creating thread 1 \n");
   rc1 = pthread_create(&t1, NULL, Add, NULL);
   if (rc1){
   	printf("ERROR; return code from pthread_create() is %d\n", rc1);
   	exit(-1);
   	}
   break;
   case 2:	
   printf("In main: creating thread 2 \n");
   rc2 = pthread_create(&t2, NULL, Sub, NULL);
   if (rc2){
   printf("ERROR; return code from pthread_create() is %d\n", rc2);
   exit(-1);
   }
   break;
   case 3:
   printf("In main: creating thread 3 \n");
   rc3 = pthread_create(&t3, NULL, Mul, NULL);
   if (rc3){
   	printf("ERROR; return code from pthread_create() is %d\n", rc3);
   	exit(-1);
   	}
   break;
 /*  case 0: 
   printf("Exiting");
   exit 0;
   break;
   default: 
   printf("Enter CORRECT CHOICE");*/
   }
   }while(1);	
   pthread_exit(NULL);
   
}
