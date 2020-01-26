#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

int state[2][N], row = 2, col, block = 0;

int dx[] = {-1, 1, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1};

int valid(int x, int y) {
    return (x >= 0 && x < row && y >= 0 && y < col);
}

void solve(int x, int y) {
    state[x][y] ^= 1;
    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny)) {
            if (state[nx][ny] & state[x][y]) {
                ++block;
            } else if (state[nx][ny] & (state[x][y] ^ 1)) {
                --block;
            }
        }
    }
    puts(block == 0 ? "Yes" : "No");
}

int main() {
//    freopen("in.txt", "r", stdin);
    int queries; scanf("%d %d", &col, &queries);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) state[i][j] = 0;
    }
    while (queries--) {
        int x, y; scanf("%d %d", &x, &y);
        x--, y--;
        solve(x, y);
    }
    return 0;
}
