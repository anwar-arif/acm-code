#include <bits/stdc++.h>
using namespace std;
#define pf printf
#define sc scanf
#define ll long long int
#define pb push_back

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define For(i,a,b) for(i=a;i<=b;i++)
#define pi acos(-1)
map<char,int>m;

void init()
{
    int n,zero,one,i,x;
    char ch;
    for(i = 1;i <= 26;i++){
        n = i+64;
        zero = one = 0;
        while(n!=0){
            if(n%2 == 0)++zero;
            if(n%2 == 1)++one;
            n /= 2;
        }
        x = (one*500)+(zero*250);
        ch = 'A'+i-1;
        m[ch] = x;
        //cout<<ch<<" "<<m[ch]<<endl;
    }
}

int main()
{
    init();
    int i,tst,j,lv,rv,lw,rw,cas = 0;
    char a[10][20];
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    init();
    sc1i(tst);
    getchar();
    while(tst--){
        string ls,rs;
        ls.clear();rs.clear();
        ls = "";rs = "";
        for(i = 1; i <= 8;i++){

            for(j = 1; j <= 18;j++){

                sc("%c",&a[i][j]);

                if(a[i][j] >= 'A' and a[i][j] <= 'Z' ){
                    if(j <= 9){ls += a[i][j];lv = i;}
                    if(j > 9) {rs += a[i][j];rv = i;}
                }
            }
            getchar();
        }

        //pf("output\n");
        //pf("left string ");cout<<ls<<endl;
        //pf("right string ");cout<<rs<<endl;
        lw = 0;rw = 0;
        for(i = 0 ; i < ls.size();i++){
            char ch = ls[i];
            lw += m[ch];
        }
        for(i = 0 ; i < rs.size();i++){
            char ch = rs[i];
            rw += m[ch];
        }
        if(lw  == rw){
                //pf("one\n");
            if(lv == rv){
                pf("Case %d:\nThe figure is correct.\n",++cas);
                continue;
            }
            else{
                    pf("Case %d:\n",++cas);
                 pf("........||........\n");pf(".../\\...||.../\\...\n");
                 pf("../..\\..||../..\\..\n");pf("./....\\.||./....\\.\n");
                 //5 th line
                 pf("/");cout<<ls;
                 for(i = 1; i <= 6 - ls.size();i++){
                    pf(".");
                 }
                 pf("\\||/");
                 cout<<rs;
                 for(i = 1; i<= 6 - rs.size();i++){
                    pf(".");
                 }
                 pf("\\");
                 pf("\n");//end 5 th line
                 pf("\\______/||\\______/\n");pf("........||........\n");
            }
        }
        else if(lw > rw){
            //pf("two\n");
             if(lv > rv){
                pf("Case %d:\nThe figure is correct.\n",++cas);
                continue;
             }
             else{
                  pf("Case %d:\n",++cas);
                  pf("........||.../\\...\n");
                  pf("........||../..\\..\n");
                  pf(".../\\...||./....\\.\n");
                  pf("../..\\..||/");cout<<rs;
                  for(i = 1; i <= 6 - rs.size();i++){
                    pf(".");
                  }
                  pf("\\");pf("\n");
                  pf("./....\\.||\\______/\n");
                  pf("/");cout<<ls;
                  for(i = 1; i<= 6-ls.size();i++){
                    pf(".");
                  }
                  pf("\\||........\n");
                  pf("\\______/||........\n");
             }
        }
        else if(lw < rw){
            //pf("three\n");
             if(lv < rv){
                pf("Case %d:\nThe figure is correct.\n",++cas);
                continue;
             }
             else{
                  pf("Case %d:\n",++cas);
                  pf(".../\\...||........\n");
                  pf("../..\\..||........\n");
                  pf("./....\\.||.../\\...\n");
                  pf("/");cout<<ls;
                  for(i = 1; i <= 6 - ls.size();i++){
                    pf(".");
                  }
                  pf("\\||../..\\..\n");
                  pf("\\______/||./....\\.\n");
                  pf("........||/");cout<<rs;
                  for(i = 1; i <= 6 - rs.size();i++){
                    pf(".");
                  }
                  pf("\\");
                  pf("\n");
                  pf("........||\\______/");
                  pf("\n");
             }
        }
    }
    return 0;
}
