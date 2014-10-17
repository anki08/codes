#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int a[10],n,status,i,j=1;
	int sum=0,sum1=0,pid;
	printf("\n enter the no. of elements : ");
	scanf("%d",&n);
	printf("\n enter the elements : ");
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	pid=fork();
	if(pid==0)
	{	
		while(j<=n)
		{
			if(a[j]%2==0)
			{
				sum=sum+a[j];
			}
			j++;
		}
	printf("\n the pid of process which is givin sum of even no. is %d ",getpid());
        printf("\n the sum of even no. is : %d ",sum);
	}
	if(pid>0)
	{
                while(j<=n)
                {
                        if(a[j]%2!=0)
                        {
                                sum1=sum1+a[j];
                        }
                        j++;
                }
        printf("\n the sum of odd no. is : %d ",sum1);
        printf("\n the pid of process which is givin sum of odd no. is %d ",getpid());
        printf("\n");
	wait(&status);
	}
	return 0;
}
			
