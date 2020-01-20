#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;


/// finding distinct elements in a range with MO`s algo

int block, n, cnt[N], arr[N], ans[N], unq;

struct data {
    int L, R, id;
    data(){}
    data(int L, int R, int id):
        L(L), R(R), id(id) {}

    bool operator < (const data &p) const {
        if (L / block != p.L / block) {
            return L / block < p.L / block;
        }
        return R < p.R;
    }
}Q[N];

void ins(int pos) {
    cnt[arr[pos]]++;
    if (cnt[arr[pos]] == 1) unq += 1;
}

void del(int pos) {
    cnt[arr[pos]]--;
    if (cnt[arr[pos]] == 0) unq -= 1;
}

int main() {
//    freopen("in.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));

    int queries; scanf("%d %d", &n, &queries);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    block = (int) sqrt(n) + 1;
    for (int i = 0; i < queries; i++) {
        int l, r; scanf("%d %d", &l, &r);
        --l, --r;
        Q[i] = data(l, r, i);
    }

    sort(Q, Q + queries);
    unq = 0;
    int curL = 0, curR = 0;

    for (int i = 0; i < queries; i++) {
        int L = Q[i].L, R = Q[i].R;

        while (curL < L) del(curL++);
        while (curL > L) ins(curL - 1), curL--;
        while (curR <= R) ins(curR++);
        while (curR > R + 1) del(curR - 1), curR--;

        ans[Q[i].id] = unq;
    }

    for (int i = 0; i < queries; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

/// complexity N*sqrt(N)*log N
