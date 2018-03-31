#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#define pi acos(-1.0)
#define INF 0x3fffffff
using namespace std;

string check;

bool palindrome()
{
    int len=check.size();
    for(int i=0; i<len/2; i++)
    {
        if(check[i]!=check[len-i-1])return false;
    }
    return true;
}

int main()
{

    string a,temp,ck,res;
    char line[10010];
    while(gets(line))
    {
        temp.clear();
        res=string(line);
        for(int i=0; i<strlen(line); i++)
        {
            temp=temp+line[i];
            ck=temp;
            reverse(ck.begin(),ck.end());
            check=res+ck;
            if(palindrome())
            {
                cout<<check<<endl;
                break;
            }
        }
    }
    return 0;
}
