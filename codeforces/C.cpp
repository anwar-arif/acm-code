#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

int n, arr[N], pos[N];
vector <pair<int, int>> ans;

void alter(int b, int c) {
    ans.push_back({b, c});
    pos[arr[b]] = c;
    pos[arr[c]] = b;
    swap(arr[b], arr[c]);
    cerr << b << " " << c << endl;
}

void solve(int b) {
    cerr << b << endl;
    int mid = (n / 2), c = pos[b], a = 1, d = n;
    if (abs(b - c) >= mid) {
        alter(b, c);
    } else if (b <= mid) {
        alter(a, c);
        alter(a, d);
        alter(b, d);
        alter(a, d);
        alter(a, c);
    } else {

    }
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] != i) {
            solve(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cerr << arr[i] << " = ";
    }cerr << endl;

    int len = (int) ans.size();
    cout << len << endl;
    for (auto p: ans) {
        cout << p.first << " " << p.second << endl;
    }
    return 0 ;
}
