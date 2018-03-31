#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int mod = 1000000007;
typedef long long int ll;

ll tree[N*4] , a[N] , arr[N];

void update(ll node , ll b , ll e ,ll i , ll j , ll v){
    if(e < i || b > j)return ;
    if(b >= i && e <= j){
        tree[node] += v;
        if(tree[node] >= mod)tree[node] %= mod;
        return;
    }
    ll lft , rt , mid ;
    lft = node * 2 ; rt = lft + 1; mid = (b + e) / 2;
    update(lft , b , mid , i , j , v);
    update(rt , mid+1 , e , i , j , v);
    tree[node] = tree[lft] + tree[rt];
}

ll query(ll node , ll b , ll e , ll i , ll j){
    if(e < i || b > j)return 0;
    if(b >= i && e <= j)return tree[node] ;
    ll lft , rt , mid;
    lft = node * 2 ; rt = lft + 1 ; mid = (b + e) / 2;
    return ( query(lft , b , mid , i , j) + query(rt , mid + 1 , e , i , j) );
}

int main(){
    int tst , cas = 0;
    scanf("%d",&tst);
    ll x , n;
    while(tst--){
        memset(tree , 0 , sizeof(tree));
        scanf("%lld",&n);
        for(int i = 1;i <= (int)n ;i++){
            scanf("%lld",&a[i]);
            arr[i] = a[i];
        }
        sort(a+1 , a+1+n);
        ll res = 0;
        for(int i = 1;i <= n;i++){
            ll val = arr[i] ;
            ll lo = 1, hi = n , mid;
            while(lo <= hi){
                mid = (lo + hi) / 2;
                if(a[mid] < val){
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            ll ans = 1;
            if(lo > 1)ans += query(1 ,1 , n , 1 , lo - 1);
            ans %= mod;
            update(1 , 1 , n , lo , lo , ans);
        }
        printf("Case %d: %lld\n",++cas,tree[1] % mod);
    }
    return 0;
}
