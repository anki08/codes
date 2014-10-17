                                                                                        
main()
{
        printf("%d",f(8));
}
                                                                                        
int f(int i)
{
        return ((--i>1)? f(i) - f(i-1):0);
}

