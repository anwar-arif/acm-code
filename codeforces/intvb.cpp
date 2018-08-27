#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

class Solution {
public:
    vector<int> rodCut(int A, vector<int> &B) ;
};

const int big = (int) 2e9 ;
int **dp ;
vector< int > res , cuts ;

int F( int i , int j ) {
    if( j - i <= 1 ) return 0 ;
    int &ret = dp[i][j] ;
    if( ret != -1 ) return ret ;
    ret = big ;
    for( int k = i + 1 ; k <= j - 1 ; k++ ) {
        ret = min( ret , (cuts[j] - cuts[i]) + F(i , k) + F(k , j) ) ;
    }
    return ret ;
}

void P( int i , int j ) {
    if( j - i <= 1 ) return ;
    int nw = F(i , j) ;
    for( int k = i + 1 ; k <= j - 1 ; k++ ) {
        if( (cuts[j] - cuts[i]) + F(i , k) + F(k , j) == nw ) {
            res.push_back(cuts[k]) ;
            P(i , k) ;
            P(k , j) ;
            return ;
        }
    }
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    res.clear() ; cuts.clear() ;
    cuts.push_back(0) ; cuts.push_back(A) ;
    for( int x : B ) cuts.push_back(x) ;
    sort( cuts.begin() , cuts.end() ) ;
    int len = (int) cuts.size() ;
    dp = new int *[len + 2] ;
    for( int i = 0 ; i < len + 2 ; i++ ) {
        dp[i] = new int [len + 2] ;
        for( int j = 0 ; j < len + 2 ; j++ ) {
            dp[i][j] = -1 ;
        }
    }
    F(0 , len - 1) ;
    P(0 , len - 1) ;
    return res ;
}

int main() {
    Solution sln ;
    vector< int > v = {3} ;
    vector< int > res = sln.rodCut(5 , v) ;
    for( int x : res ) {
        cout << x << endl ;
    }
    return 0 ;
}
