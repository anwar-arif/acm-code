char str[20];

void palin(int n)
{
     sprintf(str, "%d", n);
     puts(str);
}

int main()
{
    int n;
    while(sc1i(n) != EOF)
    {
         palin(n);
    }
    return 0;
}

