#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int C = 20+5 ;

vector<int>g[N];
int sz[N] , cnt[N] , col[N] , ans[N][C];
bool big[N] ;

void getsz(int u , int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v != p){
            getsz(v , u);
            sz[u] += sz[v];
        }
    }
}

void add(int u , int p , int x){
    cnt[ col[u] ] += x;
    for(auto v : g[u]){
        if(v != p && !big[v]){
            add(v , u , x);
        }
    }
}

void dfs(int u , int p , bool keep){
    int mx = -1 , bigChild = -1;

    for(auto v : g[u]){
        if(v != p && sz[v] > mx){
            mx = sz[v] , bigChild = v;
        }
    }

    for(auto v : g[u]){
        if(v != p && v != bigChild){
            ///run a dfs on small childs and clear them from cnt
            dfs(v , u , 0);
        }
    }

    if(bigChild != -1){
        /// bigChild marked as big and not cleared from cnt
        dfs(bigChild , u , 1) , big[ bigChild ] = 1;
    }

    add(u , p , 1) ;
    ///now cnt[c] is the number of vertices in subtree of
    ///vertex u that has color c. You can answer the queries easily.

    for(int i = 1;i <= C-5 ;i++){
        ans[u][i] = cnt[i] ;
    }

    if(bigChild != -1){
        big[bigChild] = 0;
    }

    if(keep == 0){
        add(u , p , -1);
    }
}

///complexity O(nlogn)

void reset(){
    rep(i , 0 , N-2){
        g[i].clear();
        cnt[i] = 0 ;
        sz[i] = 0 ;
        big[i] = false;
    }
}

///problem : how many vertices in subtree of vertex v are colored with color c

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    int n , u , v ;
    while(sc1i(n) != EOF){
        reset();
        for(int i = 1 ;i <= n;i++){
            sc1i(col[i]);
        }
        for(int i = 1;i <= n-1 ;i++){
            sc2i(u , v) ;
            g[u].pb(v);
            g[v].pb(u);
        }
        getsz(1 , -1);
        dfs(1 , -1 , 1);
        for(int i = 1;i <= n;i++){
            pf("%d ",ans[i][1]);
        }
        pf("\n");
    }
    return 0;
}
