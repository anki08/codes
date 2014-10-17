
#define prn(a) printf(" %d ",a)
#define print(a,b,c) prn(a), prn(b), prn(c)
#define max(a,b)  (a<b)? b:a
main()
{
int x=1, y=2;
print(max(x++,y),x,y);
print(max(x++,y),x,y);
}

