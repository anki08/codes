 #include<stdio.h>


void mergeSort(long int arr[],long int n,long int low,long int mid,long int high);
void partition(long int n,long int arr[],long int low,long int high);

int main(){
   
    long int i,n;

    //printf("Enter the total number of elements: ");
    scanf("%ld",&n);
   long int merge[n];

    //printf("Enter the elements which to be sort: ");
    for(i=0;i<n;i++){
         scanf("%ld",&merge[i]);
    }

    partition(n,merge,0,n-1);

    //printf("After merge sorting elements are: ");
    for(i=0;i<n;i++){
         printf("%ld\n ",merge[i]);
    }

   return 0;
}

void partition(long int n,long int arr[],long int low,long int high){

    long int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(n,arr,low,mid);
         partition(n,arr,mid+1,high);
         mergeSort(arr,n,low,mid,high);
    }
}

void mergeSort(long int arr[],long int n,long int low,long int mid,long int high){

    long int i,m,k,l,temp[n];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
