#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e8;

int tree[3 * N], n, arr[N], lft[N], rgt[N], x;

void upd(int node, int b, int e, int i, int j) {
    if (e < i || b > j) return;
    if (b >= i && e <= j) {
        tree[node] = 1;
        return;
    }
    int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
    upd(lft, b, mid, i, j);
    upd(rt, mid + 1, e, i, j);
    tree[node] = (tree[lft] + tree[rt]);
}

int query(int node, int b, int e, int i, int j) {
    if (e < i || b > j) return 0;
    if (b >= i && e <= j) return tree[node];
    int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
    int p = query(lft, b, mid, i, j);
    int q = query(rt, mid + 1, e, i, j);
    return (p + q);
}

int main() {
    freopen("in.txt", "r", stdin);
    memset(tree, 0, sizeof(tree));
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = n; i >= 1; i--) {
        rgt[i] = query(1, 1, n, 1, arr[i] - 1);
        upd(1, 1, n, arr[i], arr[i]);
    }
    vector <pair<int, int> > v;
    int j = 1;
    for (int i = 1; i <= n; i++) {
        int mn = arr[i], mx = arr[i];
        while (j + 1 <= n && arr[j] >= arr[i] && (mn == 1 || mx == n)) {
            if (rgt[j] == 0) {
                if (arr[j] < x) {
                    v.push_back({arr[j] + 1, n});
                }
                else {
                    v.push_back({1, arr[j] - 1});
                }
            }
            j += 1;
            mn = min(arr[j], mn);
            mx = max(arr[j], mx);
        }
        i = j;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int ans = v.size();
    printf("%d\n", ans);
    return 0 ;
}
