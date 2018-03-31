#include <bits/stdc++.h>
using namespace std;

const int N = 1000+5;

double eps = 1e-7;;
double p,q,r,s,t,u;

double cal(double x){
    return (p*exp(-x))+(q*sin(x))+(r*cos(x))+(s*tan(x))+(t*x*x)+u;
}

int main(){
    double x;
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u) != EOF){
        if(cal(0)*cal(1) > 0){printf("No solution\n");continue;}
        double lo = 0.0 , hi = 1.0 , mid;
        while(lo + eps < hi){
            double x = (lo + hi) / 2.0;
            if(cal(lo)*cal(x) <= 0.0){
                hi = x;
            }else{
                lo = x;
            }
        }
        x = (hi + lo) / 2.0;
        printf("%0.4lf\n",x);
    }
    return 0;
}
