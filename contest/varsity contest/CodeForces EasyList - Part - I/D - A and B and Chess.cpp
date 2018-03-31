#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define pb push_back
#define LL long long

int main()
{
        int i,j,bk,w;
        char ch;
        w = 0;
        bk = 0;
        for(i=0;i<8;i++)
        {
                for(j=0;j<8;j++)
                {
                        sc("%c",&ch);
                        if(ch>='A' && ch<='Z')
                        {
                                if(ch == 'Q')w = w +9;
                                if(ch == 'R')w = w + 5;
                                if(ch == 'B')w = w + 3;
                                if(ch == 'N')w = w + 3;
                                if(ch == 'P')w = w + 1;
                                if(ch == 'K')w = w + 0;
                        }

                        if(ch>='a' && ch<='z')
                        {
                                if(ch == 'q')bk = bk +9;
                                if(ch == 'r')bk = bk + 5;
                                if(ch == 'b')bk = bk + 3;
                                if(ch == 'n')bk = bk + 3;
                                if(ch == 'p')bk = bk + 1;
                                if(ch == 'k')bk = bk + 0;
                        }
                }
                getchar();
        }
        if(w > bk)pf("White\n");
        else if(w < bk)pf("Black\n");
        else if (w == bk)pf("Draw\n");
        return 0;
}
