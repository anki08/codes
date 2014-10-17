void print(int ** arr)
{
printf("0 %f, 1 %f, 2 %f\n ",arr[0][0],arr[0][1],arr[0][2]);
}
main()
{
int a[2][3]={ {1,2,3},{4,5,6}};
int **arr=a;
print(arr);
//arr++;
//print(arr);
}

