#include<bits/stdc++.h>
using namespace std;

// [2 1 3]
// [0 -1 1]
// [0 -1 0]

int solution(vector<int> &A, int S) {
    const long long MAX = (long long) 1e9;

    int len = (int) A.size();
    vector<int> arr(len);
    for (int i = 0; i < len; i++) {
        arr[i] = A[i] - S;
    }

    vector<long long> psum(len + 1, 0);
    for (int i = 0; i < len; i++) {
        psum[i] = arr[i];
        if (i) psum[i] += psum[i - 1];
    }

    unordered_map<long long, long long> count;
    count[0LL] = 1;

    long long answer = 0;
    for (int i = 0; i < len; i++) {
        answer += count[psum[i]];
        count[psum[i]] += 1;
    }

    if (answer > MAX) answer = MAX;
    return (int) answer;
}

int main() {
    vector<int> A = {2,1,3};
    vector<int> B = {0,4,3,-1};
    vector<int> C = {0};
    cout << solution(A, 2) << endl;
    cout << solution(B, 2) << endl;
    cout << solution(C, -1) << endl;
    return 0;
}