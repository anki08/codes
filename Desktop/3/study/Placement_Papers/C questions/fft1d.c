#include<stdio.h>
#include<math.h>
#include"imgio.h"
#include"cplx.h"

#define PI 3.14159

complex twiddle(N,k,fr)
int N,k,fr;
{  complex c1;
	c1.re=cos(2.0*PI*(float)k/(float)N);
	c1.im=fr*(-1.0)*sin(2.0*PI*(float)k/N);
	return(c1);
}

int bitrev(complex *vec,int N)
{
unsigned int i,j,n;
unsigned int t1,t2,t3,t4;
complex *vec2;

 n=(unsigned int)(log10(N)/log10(2));  
 vec2=(complex *)malloc(N*sizeof(complex));

 for(i=0;i<N;i++)
  { vec2[i].re=vec[i].re;
   vec2[i].im=vec[i].im; }

 for(i=0;i<N;i++)
 {
  t3=(unsigned int)0;      /* result bits */
  t4=(unsigned int)N/2;				 /* 1-bit position adder */
   t1=i;							 /* one number */
  for(j=0;j<n;j++)
   {
	 t2=t1&(unsigned int)1;		/* find least bit*/
	 if(t2==1) t3=(t3|t4); 
	 t1=t1>>1;           
	 t4=t4>>1;       
   }
  vec[i].re=vec2[t3].re;
  vec[i].im=vec2[t3].im;
 } 
return(0);
}/* fn ends*/

int fft1d(vec,N,fr)
complex *vec;
int N,fr;
{
	complex *tw,*tmp;
	int i,j,m,p; 
	int n,t2,t3,t4,t5;
	complex c1,c2,cn;

	bitrev(vec,N);       /* bit reverse values of i/p's */
  
   tmp=(complex *)malloc((N/2)*sizeof(complex));

	tw=(complex *)malloc((N/2)*sizeof(complex));
	for(i=0;i<N/2;i++)
     {tw[i]=twiddle(N,i,fr);}  /* caln of twiddle factors */
    
	n=log10(N)/log10(2.0);	/* caln of no.of stages */


 for(m=0;m<n;m++)     /* moving n-stages & each stage caln */
 {	
		t2=(int)pow(2,m);  /* Wn vector calc'n */
	for(j=0;j<t2;j++)   
	{	t4=n/(2*t2); t5=j*t4;	
		tmp[j].re=1.0,tmp[j].im=0.0;
      tmp[j+t2]=tw[t5];  /* Wn vector */
  	}
	
		t3=t2*2;		      /* multiply x(n) with Wn vector */
	for(p=0;p<N;p=p+t3)
	for(i=0;i<t3;i++)
	 {vec[i+p]=xmul(vec[i+p],tmp[i]);}
									
							
	for(p=0;p<N;p=p+t3)   /* repeating local blocks */
 	for(i=0;i<t2;i++)    /* applying butterfly's locally*/
	{ c1=xadd(vec[p+i],vec[p+i+t2]);					
	  c2=xsub(vec[p+i],vec[p+i+t2]);	  
		vec[p+i]=c1;				
	  vec[p+i+t2]=c2;		
	} 								
 }
	if(fr==-1)
	 { 
		for(i=0;i<N;i++)
	   {cn.re=(float)N;cn.im=0.0;
		 vec[i]=xdiv(vec[i],cn);}		
	 }
	free(tw);free(tmp);
	return(0);
}/* fu'n ends */

main()
{
	complex *vect;
	int i,N,fr;
	printf("enter row size:");scanf("%d",&N);
	vect=(complex *)malloc(N*sizeof(complex));
	printf("\ninput values-complx:\n");
	for(i=0;i<N;i++)
	{scanf("%f %f",&vect[i].re,&vect[i].im);}
	printf("\n 1:forward & -1:reverse   "); scanf("%d",&fr);
	fft1d(vect,N,fr);
	printf("\n dft coeff..\n");
	for(i=0;i<N;i++)
	{printf("(%.3f@@%.3f)  ",vect[i].re,vect[i].im);}
	free(vect);
}/*mian ends*/





