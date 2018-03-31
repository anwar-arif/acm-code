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
#define sc1ll(a) sc("%I64d",&a)
#define sc2ll(a,b) sc("%I64d%I64d",&a,&b)
#define sc3ll(a,b,c) sc("%I64d%I64d%I64d",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)
#define For(i,a,b) for(i=a;i<=b;i++)
#define pi acos(-1)

int main()
{
        int ;
        char a[101][101];
        while(sc1i(n) == 1){
                getchar();
                if(n == 0)break;
                for(i = 1; i <= n;i++){
                        c = 0;
                        for(j = 1; j <= n;j++){
                                sc("%c",&a[i][j]);
                                if(a[i][j] == '1')++cnt;
                        }
                        getchar();
                        row[i] = c;
                }
                for(c = 1; c<=n;i++){
                        for(r = 1; j <= n;j++){
                                if(a[r][c] == '1')++cnt;
                        }
                        col[c] = cnt;
                }
                bool t = true;
                for(r = 1; r <= n;r++){//for row
                        if(row[r]%2 != 0){
                                for(i = 1; i<=n;i++){//for col
                                        if(a[r][i] == '0'){
                                                if((col[i]+1)%2 == 0 && ((row[r] % 2 ==0))){
                                                        a[r][i] = '1';
                                                        ++col[i];
                                                        ++row[r];
                                                }
                                        }else if(a[r][i] == '1'){
                                             if((col[i]-1)%2 == 0 && ((row[r]-1)%2 ==0)){
                                                a[r][i] = '0';
                                                --col[i];
                                                --row[r];
                                             }
                                        }else{
                                            t = false;
                                        }
                                        if(!t)break;
                                }
                        }
                        if(!t)break;
                }
                if(!t){
                        pf("Corrupt\n");continue;
                }
                for(c = 1; c <= n;c++){//for col
                        if(col[c]%2 != 0){
                                for(i = 1; i <= n;i++){//for row

                                }
                        }
                }
        }
        return 0;
}
