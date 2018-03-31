#include <bits/stdc++.h>
using namespace std;

const int M = 55;

long long bc[M+5][M+5] ;

void pre() {
    for(int i = 0 ; i < M ; i++ ) bc[i][0] = 1;
    for(int i = 1; i < M ; i++ ) {
        bc[i][i] = 1 ;
        bc[i][1] = i ;
    }
    for(int i = 3; i < M ; i++ ) {
        for(int j = 2;j < i ; j++ ) {
            bc[i][j] = ( bc[i-1][j-1] + bc[i-1][j] ) ;
        }
    }
}


int main() {
    pre() ;
    int n , k ;
    while( scanf("%d %d" , &n , &k ) != EOF ) {
        cout << bc[n][k] << endl ;
    }
    return 0;
}
