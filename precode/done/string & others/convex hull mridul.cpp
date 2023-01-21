
const int N =  100000 + 5 ;


struct point
{
    double x, y;

    bool operator < (const point & p)const
    {
        if(x == p.x)return y < p.y;
        return x < p.x;
    }
} a[N+7];

int n;
vector<point>conv;

/// return o if colinear , 1 if clockwise , 2 if counter clockwise
int orientation(point p, point q, point r)
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    else if (val > 0) return 1;
    else return 2;
}

void convex_hull()
{
    int i, j, k;
    point p1, p2;
    stack<point>low;
    stack<point>up;
    sort(a, a+n);

    for(i = 0; i < n; i++)
    {
        while(SZ(low)>=2)
        {
            p2 = low.top();
            low.pop();
            p1 = low.top();
            if(orientation(p1, p2, a[i] ) == 2)
            {
                low.push(p2);
                break;
            }
        }
        low.push(a[i]);
    }
    for(i = n-1 ; i >= 0; i--)
    {
        while(SZ(up) >= 2)
        {
            p2 = up.top();
            up.pop();
            p1 = up.top();
            if(orientation(p1, p2, a[i]) == 2)
            {
                up.push(p2);
                break;
            }
        }
        up.push(a[i]);
    }
    low.pop();
    up.pop();
    while(!up.empty())
    {
        conv.pb(up.top());
        up.pop();
    }
    while(!low.empty())
    {
        conv.pb(low.top());
        low.pop();
    }
    reverse(all(conv));
}

///complexity O(nlogn)

int main()
{
    while(sc1i(n)==1)
    {
        int i, j;
        for(i = 0; i < n; i++)sc("%lf %lf",&a[i].x , &a[i].y);
        conv.clear();
        convex_hull();
        for(i = 0; i < SZ(conv); i++) pf("%.0f %.0f\n", conv[i].x, conv[i].y);
    }
    return 0;
}

