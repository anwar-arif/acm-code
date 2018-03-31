#include <bits/stdc++.h>
using namespace std;
const int N = 500+10;

vector<int>graph[N];

int match[N] ;
bool vis[N] ;

bool dfs( int u ) {
    int len = (int) graph[u].size() ;
    for( int i = 0 ; i < len ; i++ ) {
        int v = graph[u][i] ;
        if( !vis[v] ) {
            vis[v] = true ;
            if( match[v] == -1 || dfs( match[v] ) ) {
                match[v] = u ;
                return true ;
            }
        }
    }
    return false ;
}

int bpm() {
    int ret = 0 ;
    memset( match , -1 , sizeof(match) ) ;
    for( int i = 0 ; i < c ; i++ ) {
        memset( vis , false , sizeof(vis) ) ;
        if( dfs(i) ) {
            ++ret ;
        }
    }
    return ret ;
}

int main()
{
      int tst,cas = 0;
      sc1i(tst);

      while(tst--){
          for(int i = 0; i < n;i++){

            sc1i(x);

            for(int k = 1; k <= x;k++){

                sc1i(u);
                graph[i].pb(u);
            }
        }
        int ans = bpm();
        pf("Case %d: %d\n",++cas,n - ans);
      }
      return 0;
}
/**
    complexity = N*(M+E)
    N = size of set A
    M = size of set B
    E = total edges
*/
