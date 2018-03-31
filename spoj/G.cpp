#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define ll long long int
#define ull unsigned ll

#define sc1i(a) sc("%d",&a)
#define sc2i(a,b) sc("%d%d",&a,&b)
#define sc3i(a,b,c) sc("%d%d%d",&a,&b,&c)
#define sc4i(a,b,c,d) sc("%d%d%d%d",&a,&b,&c,&d)

#define sc1ll(a) sc("%lld",&a)
#define sc2ll(a,b) sc("%lld%lld",&a,&b)
#define sc3ll(a,b,c) sc("%lld%lld%lld",&a,&b,&c)
#define sc4ll(a,b,c,d) sc("%lld%lld%lld%lld",&a,&b,&c,&d)

#define mem(a,x) memset(a,x,sizeof(a))

#define rep(i,k,n) for(__typeof(n)i = k ; i <= n; i++)

const int N = (int)500000 + 15;

struct data{
    ll v , id ;
    data(){}
    data( ll _v , ll _id ) {
        v = _v ;
        id = _id ;
    }
    bool operator < (const data &dt) const {
        return v > dt.v ;
    }
} d[N] , p[N] ;

ll sumd[N] , sump[N] ;

int main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt" , "r" , stdin);
//    #endif
    freopen("buffcraft.in" , "r" , stdin ) ;
    freopen("buffcraft.out" , "w" , stdout );

    ll base , k , cd , cp , td , tp ;

    while( sc4ll( base , k , cd , cp ) != EOF ) {
        rep( i , 1 , cd ){
            sc1ll( d[i].v ) ;
            d[i].id = i ;
        }
        rep( i , 1 , cp ) {
            sc1ll( p[i].v ) ;
            p[i].id = i ;
        }

        sort( d+1 , d+1+cd ) ;
        sort( p+1 , p+1+cp ) ;

//        deb("start");
//        for( int i = 1 ; i <= cd ; i++ ) {
//            pf("d====%lld %lld\n" , d[i].v , d[i].id ) ;
//        }
//        pf("\n");
//        for( int i = 1 ; i <= cp ;i++ ) {
//            pf("p====%lld %lld\n" , p[i].v , p[i].id ) ;
//        }pf("\n");
//        deb("end");

        ll mx = 0 ;

        for( int i = 0 ;i < (int) N-2 ; i++ ) {
            sumd[i] = 0;
            sump[i] = 0;
        }
        rep( i , 1 , cd ) {
            sumd[i] = sumd[i-1] + d[i].v ;
        }
        rep( i , 1 ,cp ) {
            sump[i] = sump[i-1] + p[i].v ;
        }

//        deb("start");
//        rep( i , 1 , cd ) {
//            pf("%lld " , sumd[i] ) ;
//        }
//        pf("\n");
//        rep( i , 1 , cp ) {
//            pf("%lld " , sump[i] ) ;
//        }
//        pf("\n");
//        deb("end");

        ll x , y ;

        rep( i , 0 , k ) {

            x = ( i > cd ) ? sumd[cd] : sumd[i] ;
            y = ( k-i > cp) ? sump[cp] : sump[k-i] ;

            x += base ;
            y += 100 ;

            if( (x*y) > mx ) {
                mx = (x*y) ;

                td = (i > cd) ? cd : i ;
                tp = (k-i > cp) ? cp : k-i ;
            }
        }
        bool t = false ;
        pf("%lld %lld\n" , td , tp ) ;
        for( ll i = 1 ; i <= td ; i++ ) {
            t = true ;
            pf("%lld " , d[i].id ) ;
        }
        if(t)pf("\n");
        t = false ;
        for( ll i = 1 ; i <= tp ; i++) {
            t = true;
            pf("%lld " , p[i].id );
        }
        if(t)pf("\n");
    }
  // cerr << clock() << " ms" << endl;
    return 0;
}
