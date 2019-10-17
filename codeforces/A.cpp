#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 10;
const int inf = (int) 2e9 + 10;

char s[N];
int n, q;
long long mask[3 * N];

void build(int node, int b, int e) {
    if (b == e) {
        mask[node] = (1 << (s[b - 1] - 'a'));
        return;
    }
    int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
    build(lft, b, mid);
    build(rt, mid + 1, e);
    mask[node] = (mask[lft] | mask[rt]);
}

long long query(int node, int b, int e, int i, int j) {
    if (e < i || b > j) return 0L;
    if (b >= i && e <= j) return mask[node];
    int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
    long long p = query(lft, b, mid, i, j);
    long long q = query(rt, mid + 1, e, i, j);
    return (p | q);
}

long long query(int l, int r) {
    return query(1, 1, n, l, r);
}

void upd(int node, int b, int e, int i, int j, int c) {
    if (e < i || b > j) return;
    if (b >= i && e <= j) {
        int pre = s[b - 1] - 'a';
        mask[node] &= ~(1 << pre);
        mask[node] |= (1 << c);
        return;
    }
    int lft = 2 * node, rt = lft + 1, mid = (b + e) / 2;
    upd(lft, b ,mid, i, j, c);
    upd(rt, mid + 1, e, i, j, c);
    mask[node] = (mask[lft] | mask[rt]);
}

void upd(int l, char c) {
    upd(1, 1, n, l, l, c - 'a');
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%s %d", &s, &q);
    n = strlen(s);
    build(1, 1, n);
    while (q--) {
        int typ; scanf("%d", &typ);
        if (typ == 2) {
            int l, r; scanf("%d %d", &l, &r);
            printf("%d\n", __builtin_popcountll(query(l, r)));
        } else {
            int pos; char c; scanf("%d %c", &pos, &c);
            upd(pos, c);
            s[pos - 1] = c;
        }
    }
    return 0;
}
