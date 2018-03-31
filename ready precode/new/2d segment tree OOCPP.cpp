#include <bits/stdc++.h>

using namespace std;

#define Max 501
#define INF (1 << 30)
int P[Max][Max]; // container for 2D grid

/* 2D Segment Tree node */
struct Point {
    int x, y, mx;
    Point() {}
    Point(int x, int y, int mx) : x(x), y(y), mx(mx) {}

    bool operator < (const Point& other) const {
        return mx < other.mx;
    }
    Point operator + (const Point& other) const {
        return Point(x , y , mx+other.mx) ;
    }
};

struct Segtree2d {
    // I didn't calculate the exact size needed in terms of 2D container size.
    // If anyone, please edit the answer.
    // It's just a safe size to store nodes for MAX * MAX 2D grids which won't cause stack overflow :)
    Point T[500000]; // TODO: calculate the accurate space needed
    int Lazy[500000];
    int n, m;

    // initialize and construct segment tree
    void init(int n, int m) {
        this -> n = n;
        this -> m = m;
        build(1, 1, 1, n, m);
    }

    // build a 2D segment tree from data [ (a1, b1), (a2, b2) ]
    // Time: O(n logn)
    Point build(int node, int a1, int b1, int a2, int b2) {
        // out of range
        if (a1 > a2 or b1 > b2)
            return Point(0, 0, 0);

        // if it is only a single index, assign value to node
        if (a1 == a2 and b1 == b2) {
            Lazy[node] = 0 ;
            return T[node] = Point(a1, b1, P[a1][b1]);
        }

        // split the tree into four segments
        Point ret = Point(0, 0, 0);
        ret = ret + build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) ;
        ret = ret + build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 );
        ret = ret + build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) ;
        ret = ret + build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2);
        Lazy[node] = 0 ;
        return T[node] = ret;
    }

    // helper function for query(int, int, int, int);
    Point querySum(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2, int carry) {
        // if we out of range, return dummy
        if (x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2)
            return Point(0, 0, 0);

        // if it is within range, return the node
        if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2){
            int mul = (( abs(x1-x2) + 1 ) * ( abs( y1-y2 ) + 1 ) ) ;
            T[node] = T[node] + Point(0 , 0 , carry*mul ) ;
            return T[node];
        }
        // split into four segments
        carry += Lazy[node] ;
        Lazy[node] = 0 ;
        Point ret = Point(0, 0, 0);
        ret = ret + querySum(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2, carry) ;
        ret = ret + querySum(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2, carry);
        ret = ret + querySum(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2, carry) ;
        ret = ret + querySum(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2, carry);

        // return the sum value
        return ret;
    }

    // query from range [ (x1, y1), (x2, y2) ]
    // Time: O(logn)
    Point querySum(int x1, int y1, int x2, int y2) {
        return querySum(1, 1, 1, n, m, x1, y1, x2, y2, 0);
    }

    // helper function for query(int, int, int, int);
    Point updateSum(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2, int val) {
        // if we out of range, return dummy
        if (x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2)
            return Point(0, 0, 0);

        // if it is within range, return the node
        if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2) {
            int mul = (( abs(x1-x2) + 1 ) * ( abs( y1-y2 ) + 1 ) ) ;
            T[node] = T[node] + Point(0, 0, val*mul );
            Lazy[node] += val ;
            return T[node];
        }

        // split into four segments
        Point ret = Point(0, 0, 0);
        ret = ret + updateSum(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2, val) ;
        ret = ret + updateSum(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2, val) ;
        ret = ret + updateSum(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2, val) ;
        ret = ret + updateSum(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2, val);

        // return the maximum value
        return T[node] = ret;
    }

    // query from range [ (x1, y1), (x2, y2) ]
    // Time: O(logn)
    Point updateSum(int x1, int y1, int x2, int y2, int val) {
        return updateSum(1, 1, 1, n, m, x1, y1, x2, y2, val);
    }

    // utility functions; these functions are virtual because they will be overridden in child class
    virtual Point maxNode(Point a, Point b) {
        return max(a, b);
    }

    // dummy node
    virtual Point def() {
        return Point(0, 0, -INF);
    }
};

/* 2D Segment Tree for range minimum query; a override of Segtree2d class */
struct Segtree2dMin : Segtree2d {
    // overload maxNode() function to return minimum value
    Point maxNode(Point a, Point b) {
        return min(a, b);
    }

    Point def() {
        return Point(0, 0, INF);
    }
};

// initialize class objects
Segtree2d Tmax;
Segtree2dMin Tmin;

/* Driver program */
// 1 based indexing on segment tree
int main(void) {
    int n, m;
    // input
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &P[i][j]);

    // initialize
    Tmax.init(n, m);
    Tmin.init(n, m);
    int x1 , y1 , x2 , y2 ;
    //modify build function to use querySum()
    scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2 ) ;
    Tmax.updateSum(x1 , y1 , x2 , y2, 2) ;
    cout << Tmax.querySum(1 , 1 , x2 , y2).mx << endl ;
    return 0;
}
