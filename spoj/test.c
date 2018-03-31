#include<stdio.h>
#include<string.h>
int main()
{
    int i, j, k, rem1, rem2, sum1, sum2;
    double digit1, digit2, percent;
    char str[26] = "abcdefghijklmnopqrstuvwxyz";
    char boy[40], girl[40], boy1[40], girl1[40];

    for(i = 0; i < strlen(str); i++)
    {
        str[i] = i+1;
    }

    while(scanf("%[^\n]%*c %[^\n]%*c", boy1, girl1) != EOF)
    {
        strcpy(boy, strlwr(boy1));
        strcpy(girl, strlwr(girl1));

        digit1 = 0;
        sum1 = 0;
        for(j = 0; j < strlen(boy); j++)
        {
            sum1 = sum1 + boy[j];
        }

        while(sum1 != 0)
        {
            rem1 = sum1 % 10;
            digit1 = digit1 + rem1;
            sum1 = sum1/10;
        }

        digit2 = 0;
        sum2 = 0;
        for(k = 0; k < strlen(girl); k++)
        {
            sum2 = sum2 + girl[k];
        }

        while(sum2 != 0)
        {
            rem2 = sum2 % 10;
            digit2 = digit2 + rem2;
            sum2 = sum2/10;
        }

        if(digit1 < digit2)
        {
            percent = (digit1/digit2)*100;

            printf("%.2lf %%\n", percent);
        }
        else
        {
            percent = (digit2/digit1)*100;

            printf("%.2lf %%\n", percent);
        }
    }

    return 0;
}
