#include<bits/stdc++.h>
using namespace std;
#define SZ(a) (int)a.size()
#define MAX 100000

string text;
int revSA[MAX],SA[MAX];
int cnt[MAX] , nxt[MAX];
bool bh[MAX],b2h[MAX];
int LCP[MAX];


bool cmp(const int &i,const int &j)
{
    return text[i]<text[j];
}

void sortFirstChar(int n)
{
    /// sort for the first char  ...
    for(int i =0 ; i<n ; i++)
        SA[i] = i;
    sort(SA,SA+n ,cmp);

    ///indentify the bucket ........
    for(int i=0 ; i<n ; i++)
    {
        bh[i] = (i==0  || text[SA[i]]!=text[SA[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket(int n)
{
    int bucket = 0;
    for(int i =0 ,j; i<n ; i=j)
    {
        j = i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}

void SetRank(int n)
{
    for(int i = 0 ; i<n ; i=nxt[i])
    {
        cnt[i] = 0;
        for(int j =i ; j<nxt[i] ; j++)
        {
            revSA[SA[j]] = i;
        }
    }
    return;
}

void findNewRank(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0)
        {
            int head = revSA[pre];
            revSA[pre] = head+cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
    return;
}

void findNewBucket(int l,int r,int step)
{
    for(int j = l  ; j<r ; j++)
    {
        int pre = SA[j] - step;
        if(pre>=0 && b2h[revSA[pre]])
        {
            for(int k = revSA[pre]+1 ; b2h[k] && !bh[k] ; k++) b2h[k] = false;
        }
    }
    return;
}

void buildSA(int n)
{
    ///start sorting in logn step ...
    sortFirstChar(n);
    for(int h =1 ; h<n ; h<<=1)
    {
        if(CountBucket(n)==n) break;
        SetRank(n);
        /// cause n-h suffix must be sorted
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;

        for(int i = 0 ; i<n ; i=nxt[i])
        {
            findNewRank(i,nxt[i] , h);
            findNewBucket(i , nxt[i] , h);
        }
        ///set the new sorted suffix array ...
        for(int i =0 ; i<n ; i++)
        {
            SA[revSA[i]] = i;
            bh[i] |= b2h[i]; ///new bucket ....
        }
    }
    return;
}

void buildLCP(int n)
{
    int len = 0;
    for(int i = 0 ;i<n ; i++)
        revSA[SA[i]] = i;
    for(int i =0 ; i< n ; i++)
    {
        int k = revSA[i];
        if(k==0)
        {
            LCP[k] = 0;
            continue;
        }
        int j = SA[k-1];
        while(text[i+len]==text[j+len]) len++;
        LCP[k] = len;
        if(len) len--;
    }
    return;
}

void printSA(int n)
{
    for(int i=0;i<n;i++) printf("%2d ",SA[i]),cout<<text.substr(SA[i])<<endl;
    puts("");
    for(int i=1;i<n;i++) printf("%2d\n",LCP[i]);
    puts("");
    return ;
}
///LCP[i] = longest common prefix of ith and (i-1)th suffix
///in sorted list
int main()
{
    string a,b;
    int n,p,q;
    int tcase,cas=1;
    scanf("%d",&tcase);
    while(tcase--)
    {
        ///start
        
	cin>>text;
        buildSA(SZ(text));
        buildLCP(SZ(text));
        printSA(SZ(text));
        ///end
    }
    return 0;
}
/**
1
mississipi
**/
