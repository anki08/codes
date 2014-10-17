/*ARYA KUMAR 09/CSE/44
NAVEEN KUMAR CHAUBEY 09/CSE/46
PRAVEEN KUMAR VERMA 09/CSE/48
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h> 
#include <unistd.h> 
#include <pthread.h> 
#define N 3
#define S 2
int A[S][S],B[S][S],C[S][S];
void *add(void *threadid)
{
   int i=0,j=0,k=0;
	printf("\nAddition\n");
	 for(i=0;i<S;i++)
		for(j=0;j<S;j++)
		{
			printf("%d\n",A[i][j]+B[i][j]);
		}
}
void *sub(void *threadid)
{
   int i=0,j=0,k=0;
	printf("Subtraction\n");
	 for(i=0;i<S;i++)
		for(j=0;j<S;j++)
		{
			printf("%d\n",A[i][j]-B[i][j]);
		}
}
void *mul(void *threadid)
{
   int i=0,j=0,k=0;
	printf("Multiplication\n");
	 for(i=0;i<S;i++)
		for(j=0;j<S;j++)
		{
			C[i][j]=0;
			for(k=0;k<S;k++)
			{
			C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
		}
	  for(i=0;i<S;i++)
		for(j=0;j<S;j++)
		{
			printf("%d\n",C[i][j]);
		}
}
int main (int argc, char *argv[])
{
int i,j;
	   printf("enter tow matrixes\n");
  for(i=0;i<S;i++)
		for(j=0;j<S;j++)
		{
			printf("enter the element\n");
			scanf("%d %d",&A[i][j],&B[i][j]);
		}
   pthread_t threads[N];
   int rc;
   long t=0;
int q;
	printf("Enter your choice\nADD=1\nSub=2\nMul=3\n");
	scanf("%d",&q);
   switch(q)
	{
	  case 1:
		t=0;
                rc = pthread_create(&threads[t], NULL, add, (void *)t);
		break;
	  case 2:
		t=1;
		rc = pthread_create(&threads[t], NULL, sub, (void *)t);
		break;
	  case 3:
		t=2;
		rc = pthread_create(&threads[t], NULL, mul, (void *)t);
   }
   pthread_exit(NULL);
return 0;
}

