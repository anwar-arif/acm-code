#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0 ;
        vector< int > first , second ;
        unordered_map< int , int > cnt ;
        sort( A.begin() , A.end() ) ;
        sort( B.begin() , B.end() ) ;
        sort( C.begin() , C.end() ) ;
        sort( D.begin() , D.end() ) ;
        for( int i = 0 ; i < A.size() ; i++ )
            for( int j = 0 ; j < B.size() ; j++ )
                cnt[A[i] + B[j]]++ ;
        for( int i = 0 ; i < C.size() ; i++ )
            for( int j = 0 ; j < D.size() ; j++ )
                ans += cnt[-(C[i] + D[j])] ;
        return ans ;
    }
};

int main() {

}
