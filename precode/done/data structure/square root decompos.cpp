#include<bits/stdc++.h>
using namespace std;

const int N = (int) 2e4 + 10;
const int inf = (int) 2e9;

vector <int> orig[N], temp[N];
int n, queries, block;

int solve() {
    int l, r, val; scanf("%d %d %d", &l, &r, &val);
    l--, r--; /// l and r are 1-based index

    int answer = 0;
    int leftBlock = l / block;
    int rightBlock = r / block;

    l -= leftBlock * block;
    r -= rightBlock * block;

    if (leftBlock == rightBlock) {
        for (int i = l; i <= r; i++) {
            if (orig[leftBlock][i] <= val) {
                answer += 1;
            }
        }
    } else {
        for (int i = l; i < (int) orig[leftBlock].size(); i++) {
            if (orig[leftBlock][i] <= val) answer += 1;
        }
        for (int i = 0; i <= r; i++) {
            if (orig[rightBlock][i] <= val) answer += 1;
        }
        for (int i = leftBlock + 1; i < rightBlock; i++) {
            answer += upper_bound(temp[i].begin(), temp[i].end(), val) - temp[i].begin();
        }
    }

    return answer;
}

int main() {
//    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &queries);
    block = (int) sqrt(n);

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        orig[i / block].push_back(x);
        temp[i / block].push_back(x);
    }

    int len = (n / block) + (n % block != 0);
    for (int i = 0; i < len; i++) {
        sort(temp[i].begin(), temp[i].end());
    }

    /// find the number of value which are
    /// smaller than or equal to val within range l,r
    while (queries--) {
        int queryType; scanf("%d", &queryType);

        if (queryType == 1) {
            printf("%d\n", solve());
        } else {
            int index, value; scanf("%d %d", &index, &value);
            index -= 1; /// index is 1-based

            int blockNo = index / block;
            index -= blockNo * block;

            orig[blockNo][index] = value;
            temp[blockNo] = orig[blockNo];

            sort(temp[blockNo].begin(), temp[blockNo].end());
        }
    }
    return 0;
}
