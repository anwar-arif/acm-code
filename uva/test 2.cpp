
#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define ll long long int

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define mem(a,x) memset(a,x,sizeof(a))



template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1);}//N^P
template<class T> T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);}//gcd(a,b)

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

#define SIZ 10000+5

#define Mx 2000000+5

bool is_lucky[Mx+5];
int tree[3*Mx] , lucky[Mx+5];

void build(int node,int b,int e)
{
    if(b == e)
    {
        tree[node] = is_lucky[b] = (b&1)?1:0;
        return;
    }
    int lft,rt,mid;
    lft = node*2;
    rt = lft + 1;
    mid = (b+e)/2;
    build(lft,b,mid);
    build(rt,mid+1,e);
    tree[node] = tree[lft] + tree[rt];
}

void update(int node,int b,int e,int x)
{
    if(b > x or e < x)return;
    if(b >= x and e <= x)
    {
        tree[node] = is_lucky[x] = 0;
        return;
    }
    int lft,rt,mid;
    lft = node*2;
    rt = lft + 1;
    mid = (b+e)/2;
    if(x > tree[lft])update(rt,mid+1,e,x-tree[lft]);
    else update(lft,b,mid+1,x);
    tree[node] = tree[lft] + tree[rt];
}

int main()
{
//      #ifndef ONLINE_JUDGE
//      //Read;
//      //Write;
//      #endif
      deb("asdffjasldf");
      mem(is_lucky,false);
      deb("adf");
      build(1,1,Mx);
deb("ok");
      lucky[1] = 1;
      int k = 1;
      for(int i = 3; i<=Mx;i+=2)
      {
          if(is_lucky[i])
          {
              lucky[++k] = i;
              int pos = (Mx/i)*i;
              for(int j = pos;j>=i;j -= i)
              {
                  update(1,1,Mx,j);
              }
          }
      }
      int n;
      while(sc1i(n) != EOF)
      {
          if(n&1)pf("%d is not the sum of two luckies!\n",n);
          else
          {
              int mid = lower_bound(lucky+1,lucky+1+k,n/2)-lucky;
              if(!is_lucky[n/2])--mid;
              bool t = false;
              for(int i = mid;i>=1;i--)
              {
                  if(is_lucky[i]==true and is_lucky[n-lucky[i]])
                  {
                      pf("%d is the sum of %d and %d.\n",lucky[i],n-lucky[i]);
                      t = true;break;
                  }
              }
              if(!t)pf("%d is not the sum of two luckies!\n",n);
          }
      }
      return 0;
}
