/*
ID:anwarho2
LANG:C++
TASK:friday
*/
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>
using namespace std;

int month[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day[8];

bool leapyear(int y)
{
        if( (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 )return true;
        return false;
}

int main()
{
        int n,i,j,x,d,st;
        //freopen("friday.in","r",stdin);
        //freopen("friday.out","w",stdout);
        while(scanf("%d",&n)==1)
        {
                st=3;

                memset(day,0,sizeof(day));
                for(i=1900;i<= 1900+n-1;i++)
                {
                        for(j=1;j<=12;j++)
                        {
                                x=(st+5)%7;
                                if(x==0){x=7;}
                                day[x]++;
                                if(leapyear(i) && j==2)
                                {
                                        d=29;
                                        st=(st+d)%7;
                                        if(st==0)st=7;
                                        continue;
                                }
                                d=month[j];
                                st=(st+d)%7;
                                if(st==0){st=7;}
                        }
                }
                printf("%d %d %d %d %d %d %d\n",day[1],day[2],day[3],day[4],day[5],day[6],day[7]);
        }
        return 0;
}
