#include<bits/stdc++.h>
using namespace std ;

double n , m ,k , p ;

int main(){
    int tst , cas = 0 ;
    scanf("%d" , &tst ) ;
    while( tst-- ) {
        sc("%lf%lf%lf%lf" , &n , &m , &k , &p ) ;
        printf("Case %d: %0.9f\n" , ++cas , n*p*k ) ;
    }
    return 0;
}

