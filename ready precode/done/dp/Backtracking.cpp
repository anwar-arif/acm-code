#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e6 + 10;
const int inf = (int) 2e9;

vector <char> arr{'a', 'b', 'c', 'd'};
vector <char> result;
int taken[20], n;

void backtrack() {
    if (result.size() == n) {
        for (char c: result) {
            printf("%c", c);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (taken[i] == 0) {
            taken[i] = 1;
            result.push_back(arr[i]);

            backtrack();

            taken[i] = 0;
            result.pop_back();
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    n = (int) arr.size();
    memset(taken, 0, sizeof(taken));

    backtrack();

    return 0;
}
/*
Complexity: O(2 ^ n)
*/
