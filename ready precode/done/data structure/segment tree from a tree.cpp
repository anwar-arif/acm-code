#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

int tree[4 * N], lazy[4 * N], arr[N], tym = 0;
int start[N], fin[N], col[N];

vector<int> g[N];

void dfs(int u, int p) {
    start[u] = ++tym;
    arr[tym] = col[u];
    int len = (int)g[u].size();
    for (int i = 0; i < len; i++) {
        int v = g[u][i];
        if (v == p) continue;
        dfs(v, u);
    }
    fin[u] = tym;
}

void mrg(int node, int lft, int rt) {
    tree[node] = tree[lft] + tree[rt];
}

void build (int node, int b, int e) {
    if (b == e) {
        tree[node] = arr[b];
        lazy[node] = 0;
        return;
    }
    int lft = 2 * node , rt = lft + 1, mid = (b + e) / 2;
    build(lft, b, mid);
    build(rt, mid + 1, e);
    mrg(node, lft, rt );
    lazy[node] = 0;
}

void push_down(int node, int lft, int rt, int b, int e) {
    if ((lazy[node] & 1)) {
        tree[node] = (e - b + 1) - tree[node];
        if (b != e) {
            ++lazy[lft];
            ++lazy[rt];
        }
    }
    lazy[node] = 0;
}

void update(int node, int b, int e, int i, int j) {
    int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
    push_down(node, lft, rt, b, e );
    if (e < i || b > j) return ;
    if (b >= i && e <= j) {
        ++lazy[node];
        push_down(node, lft, rt, b, e);
        return;
    }
    update(lft, b, mid, i, j);
    update(rt, mid + 1, e, i, j);
    mrg(node, lft, rt);
}

int query(int node, int b, int e, int i, int j) {
    int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
    push_down(node, lft, rt, b, e);
    if (e < i || b > j) return 0;
    if (b >= i && e <= j) {
        push_down(node, lft, rt, b, e);
        return tree[node];
    }
    return (query(lft, b, mid, i, j) + query(rt, mid + 1, e, i, j));
}
/***
    pow v describes a task to switch lights in the subtree of vertex v.
    get v describes a task to count the number of rooms in the subtree of v, in which the light is turned on
*/

int main() {
    freopen("input.txt", "r", stdin);
    int n, p, u;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p);
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &col[i]);
    }
    dfs(1, -1);
    build(1, 1, n);
    int q ; scanf("%d", &q);
    char typ[10];
    while (q--) {
        scanf("%s", typ);
        scanf("%d", &u);
        if (strcmp("get", typ) == 0) {
            int ans = query(1, 1, n, start[u], fin[u]);
            printf("%d\n", ans);
        }
        else{
            update(1, 1, n ,start[u], fin[u]);
        }
    }
    return 0 ;
}
/***
input
10
1 2 3 3 5 5 7 7 8
0 0 0 0 1 1 1 1 0 0
10
pow 3
get 1
pow 9
get 1
get 1
get 8
pow 8
pow 4
get 10
pow 2
*/

/***
output
4
3
3
1
0
*/
