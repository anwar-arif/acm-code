#include <bits/stdc++.h>
using namespace std;

#define pf printf
#define sc scanf
#define PI acos(-1)

using namespace std;

int main(){

    int s,a;
    string unid;

    double alpha,d,L;

    while(cin>>s>>a>>unid){

        if(unid=="deg") alpha=a*PI/180;

        else if(unid=="min")  alpha=a*PI/180/60;

        alpha=fmin(alpha,2*PI-alpha);

        L=(6440+s)*alpha;
        d=2*(6440+s)*sin(alpha/2);

        printf("%.6f %.6f\n",L,d);
    }

    return 0;
}
