#include <bits/stdc++.h>
using namespace std;


#define pf printf
#define sc scanf
#define ll long long int

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define pb push_back
#define pi acos(-1.0)
#define mem(a,x) memset(a,x,sizeof(a))
#define all(v) v.begin(),v.end()
#define SZ(a) (int)a.size()
#define MP make_pair

template<class T1> void deb(T1 e1){cout<<e1<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


const int N = 100000+5;
int mod;

struct matrix{
    int v[7][7] , row , col;
};


matrix multiply(matrix a, matrix b) {

  matrix r;

  r.row = a.row;
  r.col = b.col;

  for (int i = 1; i <= r.row; i++) {

    for (int j = 1; j <= r.col; j++) {

      int sum = 0;

      for (int k = 1; k <= a.col;  k++) {

        sum += a.v[i][k] * b.v[k][j];

        sum %= mod;
      }

      r.v[i][j] = sum;

    }

  }
  return r;
}

/// returns mat^p
matrix power(matrix mat, int p) {

  if (p == 1) return mat;

  if (p % 2 == 1){

      matrix ret;
      ret = multiply(mat, power(mat, p - 1));
      return ret;
  }
  else{
      matrix ret = power(mat, p / 2);
      ret = multiply(ret, ret);
      return ret;
  }
}

int main(){
    int tst , a , b , n , m , cas = 0;

    sc1i(tst);
    while(tst--){
        sc4i(a,b,n,m);

        mod = 1;
        for(int i = 1; i <= m;i++)mod *= 10;

        matrix mat;
        mat.row = 2 ; mat.col = 2;
        mat.v[1][1] = mat.v[1][2] = mat.v[2][1] = 1;
        mat.v[2][2] = 0;
        pf("Case %d: ",++cas);

        if(n < 3){
            if(n == 0)cout<< a%mod << endl;
            if(n == 1)cout<< b%mod << endl;
            else cout<< (a+b)%mod << endl;
        }
        else{
            mat = power(mat , n-1);
            int ans = b*mat.v[1][1] + a*mat.v[1][2];
            ans %= mod;
            cout<< ans << endl;
        }
    }
    return 0;
}

