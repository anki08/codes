#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define max 10
void display(char);
int r1,r2,c1,c2,res_mat[max][max],mat1[max][max],mat2[max][max];

void *add_thread(void *t)
{
	int r,c,*rc;

		rc=(int *) t;
		r=rc[0];
		c=rc[1];

		res_mat[r][c]=mat1[r][c]+mat2[r][c];


	return(NULL);
}
void *sub_thread(void *t)
{
	int r,c,*rc;

		rc=(int *) t;
		r=rc[0];
		c=rc[1];

		res_mat[r][c]=mat1[r][c]-mat2[r][c];


	return(NULL);
}
void *mult_thread(void *t)
{
	int i,r,c,tot=0,*rc;

	rc=(int *) t;
	r=rc[0];
	c=rc[1];

	for(i=0;i<c1;i++)
	{
		tot += mat1[r][i]*mat2[i][c];
	}

	res_mat[r][c]=tot;

	return(NULL);
}

void accept(int mat[max][max], int r,int c)
{
	int i,j;

	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			printf("\nEnter the value at [%d:%d] : \n",i,j);
			scanf("%d",&mat[i][j]);
		}
	printf("\n");
}

void display(char ch)
	{
		int i,j;
		printf("displaying");
		printf("\n");
		for(i=0;i<r1||i<r2;i++)
			{
				for(j=0;j<c1;j++)
					{
						if(i<r1)
						printf(" %d ",mat1[i][j]);
					}


				if(i==r1/2)
					printf("\t%c\t",ch);
				else
					printf("\t\t");
				for(j=0;j<c2;j++)
					{
						if(i<r2)
						printf(" %d ",mat2[i][j]);
					}

				if(i==r1/2)
					printf("\t=\t");
				else
					printf("\t\t");

				for(j=0;j<c2;j++)
					{
						if(i<r1)
						printf(" %d ",res_mat[i][j]);
					}

				printf("\n");
			}
		printf("\n");
	}


int main(void)
	{
		int i,j,rc[2],z;
		pthread_t p[max][max];

		printf("\nEnter the number of rows for first matrix : \n");
		scanf("%d",&r1);
		printf("\n");

		printf("\nEnter the number of columns for first matrix : \n");
		scanf("%d",&c1);
		printf("\n");

		accept(mat1,r1,c1);

		printf("\nEnter the number of rows for second matrix : \n");
		scanf("%d",&r2);
		printf("\n");

		printf("\nEnter the number of columns for second matrix : \n");
		scanf("%d",&c2);
		printf("\n");

		accept(mat2,r2,c2);
		printf("\nPress 1 for addition 2 for subtraction 3 for multiplication : \n");
		scanf("%d",&z);

		switch(z)
		{
		  	case 1 :

			if(r1==r2 && c1==c2)
				{

					 for(i=0;i<r1;i++)
					for(j=0;j<c2;j++)
						{

							rc[0]= i;
							rc[1]= j;
					  pthread_create(&p[i][j],NULL,add_thread,rc);


				          }
				 }
				 display('+');
		             break;
		        case 2 :

			if(r1==r2 && c1==c2)
				{

					 for(i=0;i<r1;i++)
					for(j=0;j<c2;j++)
						{

							rc[0]= i;
							rc[1]= j;
					  pthread_create(&p[i][j],NULL,sub_thread,rc);


				          }
				 }
				 display('-');
		             break;
			case 3 :
				if(c1==r2)
				{
					for(i=0;i<r1;i++)
					for(j=0;j<c2;j++)
						{

							rc[0]= i;
							rc[1]= j;
							pthread_create(&p[i][j],NULL,mult_thread,rc);

						}
			}

		 display('*');
		break;
		return 1;
		default:
		 exit(0);
	}
	}

