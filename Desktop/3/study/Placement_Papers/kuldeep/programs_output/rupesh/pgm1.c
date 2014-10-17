int power2(int a){
int b;
b=a-1;
if((a^b)>>1==b) return 1;
else return 0;
}

int main(){
int a;
scanf("%d",&a);
printf("%d",power2(a));
}

