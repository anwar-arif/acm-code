#include<bits/stdc++.h>
using namespace std;

const int N = (int) 3e5 + 10;
const int inf = (int) 2e9;

vector <int> pos[N];
int n, tree[4 * N], arr[N], brr[N];

void upd(int node, int b, int e, int i, int j, int v) {
    if (e < i || b > j) return;
    if (b >= i && e <= j) {
        tree[node] = v;
        return;
    }
    int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
    upd(lft, b, mid, i, j, v);
    upd(rt, mid + 1, e, i, j, v);
    tree[node] = min(tree[lft], tree[rt]);
}

int query(int node, int b, int e, int i, int j) {
    if (e < i || b > j) return inf;
    if (b >= i && e <= j) return tree[node];
    int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
    int x = query(lft, b, mid, i, j);
    int y = query(rt, mid + 1, e, i, j);
    return min(x, y);
}

int main() {
//    freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) pos[i].clear();
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            pos[x].push_back(i);
        }
        for (int i = 1; i <= n; i++) scanf("%d", &brr[i]);
        for (int i = 1; i <= n; i++) upd(1, 1, n, i, i, inf);
        for (int i = 1; i <= n; i++) {
            reverse(pos[i].begin(), pos[i].end());
            if (!pos[i].empty()) {
                upd(1, 1, n, i, i, pos[i].back());
            }
        }
        bool yes = true;
        for (int i = 1; i <= n; i++) {
            int b = brr[i];
            if (pos[b].empty()) {
                yes = false;
                break;
            }
            int p = pos[b].back();
            if (query(1, 1, n, 1, b) < p) {
                yes = false;
                break;
            }
            pos[b].pop_back();
            upd(1, 1, n, b, b, pos[b].empty() ? inf : pos[b].back());
        }
        puts(yes ? "YES" : "NO");
    }
    return 0 ;
}
