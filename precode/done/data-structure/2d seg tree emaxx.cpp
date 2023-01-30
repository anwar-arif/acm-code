#include < bits/stdc++.h>
using namespace std;

const int N = 1005;

int t[2046][2046] ,n , m ;

void build_y (int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			t[vx][vy] = 0;
		else
			t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
	else {
		int my = (ly + ry) / 2;

		build_y (vx, lx, rx, vy*2, ly, my);
		build_y (vx, lx, rx, vy*2+1, my+1, ry);

		t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
	}
}

void build_x (int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;

		build_x (vx*2, lx, mx);
		build_x (vx*2+1, mx+1, rx);
	}
	build_y (vx, lx, rx, 1, 0, m-1);
}

void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
	if (ly == ry) {
		if (lx == rx)
			t[vx][vy] = new_val;
		else
			t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
	}
	else {
		int my = (ly + ry) / 2;

		if (y <= my)
			update_y (vx, lx, rx, vy*2, ly, my, x, y, new_val);

		else
			update_y (vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);

		t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
	}
}

void update_x (int vx, int lx, int rx, int x, int y, int new_val) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;

		if (x <= mx)
			update_x (vx*2, lx, mx, x, y, new_val);

		else
			update_x (vx*2+1, mx+1, rx, x, y, new_val);
	}
	update_y (vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

int sum_y (int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;

	if (ly == tly && try_ == ry)
		return t[vx][vy];

	int tmy = (tly + try_) / 2;

	return sum_y (vx, vy*2, tly, tmy, ly, min(ry,tmy))
		+ sum_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry);
}

int sum_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;

	if (lx == tlx && trx == rx)
		return sum_y (vx, 1, 0, m-1, ly, ry);

	int tmx = (tlx + trx) / 2;

	return sum_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
		+ sum_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry);
}

///update , query , build all complexity O(log (row) * log (col) )
///used 0 based indexing

int main(){
    n = m = 1003;
    int t,x1,x2,y2,y1,ans,q;
    int tst,cas = 0;
    sc1i(tst);

    while(tst--){
        build_x(1,0,n-1);
        sc1i(q);
        pf("Case %d:\n",++cas);

        while(q--){
            sc1i(t);
            if(!t){
                sc2i(x1,y1);
                update_x(1,0,n-1,x1,y1,1);
            }
            else{
                sc4i(x1,y1,x2,y2);
                int ans = sum_x(1,0,n-1,x1,x2,y1,y2);
                pf("%d\n",ans);
            }
        }
    }
    return 0;
}
