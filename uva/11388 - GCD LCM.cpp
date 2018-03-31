#include<bits/stdc++.h>
using namespace std;

int main(){
    int tst,cas = 0;
    scanf("%d",&tst);
    long long g , l;
    while(tst--){
        scanf("%lld %lld",&g,&l);
        if(l % g != 0)printf("-1\n");
        else printf("%lld %lld\n",g,l);
    }
    return 0;
}
