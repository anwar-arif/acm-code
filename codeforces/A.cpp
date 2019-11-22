#include<bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 10;

int main() {
//    freopen("in.txt", "r", stdin);
    int bits = 0;
    while ((1LL << bits) < (long long) 1e15) {
        bits++;
    }
    cout << bits << endl;
    return 0;
}
