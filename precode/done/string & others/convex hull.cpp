#include<bits/stdc++.h>
using namespace std;
#define pf printf
const int N =  10000+5;

struct point
{
    int x,y;
};

int sswap(point &p1 , point &p2)
{
    point tmp = p1;
    p1 = p2;
    p2 = tmp;
}

point p0;

int distsq(point p1,point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) - (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(point p,point q,point r)
{
    int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if(val == 0)return 0;
    return (val > 0)?1 : 2;
}

int cmp(const void *vp1,const void *vp2)
{
    point *p1 = (point *)vp1;
    point *p2 = (point *)vp2;
    int o = orientation(p0,*p1,*p2);
    if(o == 0){
        return distsq(p0,*p2) >= distsq(p0,*p1) ? -1: 1;
    }
    return (o==2)?-1:1;
}

point nextToTop(stack<point>&s)
{
    point p = s.top();
    s.pop();
    point res = s.top();
    s.push(p);
    return res;
}

void convex_hull(point points[],int n)
{
    int ymin = points[0].y, indx = 0;
    for(int i = 1 ; i < n;i++)
    {
        if(points[i].y < ymin or (points[i].y==ymin and
            points[i].x < points[indx].x))
        {
            ymin = points[i].y; indx = i;
        }
    }

    sswap(points[0],points[indx]);
    p0 = points[0];

    qsort(&points[1],n-1,sizeof(point),cmp);

    int m = 1;
    for(int i = 1; i< n;i++)
    {
        while(i < n-1 and (orientation(p0,points[i],points[i+1]) == 0))i++;
        points[m] = points[i];
        m++;
    }

    if(m < 3){
        pf("convex hul is not possible\n");return;
    }

    stack<point>s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    for(int i = 3; i < m;i++)
    {
        while(orientation(nextToTop(s),s.top(),points[i]) != 2){
            s.pop();
        }
        s.push(points[i]);
    }

    while(!s.empty())
    {
        point p = s.top();
        cout<<"("<<p.x<<", "<<p.y<<")"<<endl;
        s.pop();
    }
}

int main()
{
      #ifndef ONLINE_JUDGE
      //Read;
      //Write;
      #endif
      point points[] = { {1 , 1} , { 1, -1}  , {-1,-1} , {-1,1} } ;

      int n = sizeof(points)/sizeof(points[0]);
      convex_hull(points,n);
      return 0;
}
