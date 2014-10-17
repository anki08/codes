#include<stdio.h>
#include<conio.h>
main()
{
 int A[10][10],B[10][10],R[10][10],i,j,r,c;
 clrscr();
 printf("\n\nENTER THE ORDER OF THE MATRICES YOU WANY TO ADD  :");
 scanf("%d%d",&r,&c);
 printf("\n\nEnter the elements of the first matrice   :\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("[%5d  ]  [%5d  ] element  :",i+1,j+1);
   scanf("%d",&A[i][j]);
   }
   }
 printf("\n\nEnter the elements of the second matrice   :\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("[%5d  ]  [%5d  ] element  :",i+1,j+1);
   scanf("%d",&B[i][j]);
   }
   }
   getche();
   clrscr();
    for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
  R[i][j]=A[i][j]+B[i][j];
  }
    }
  printf("\nThe matrices you have entered are   :\n\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%5d  ",A[i][j]);
      }
   printf("\n");
   }
   printf("\n\n  AND\n\n");
  for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%5d  ",B[i][j]);
      }
   printf("\n");
   }
   printf("\n\nTHE RESULT OF MATRICE ADDITION IS \n\n");
   for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%5d  ",R[i][j]);
      }
   printf("\n");
   }
   getche();
   }