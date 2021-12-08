#include<bits/stdc++.h>
using namespace std;

void add(int val, int &unq, vector<int> &count) {
    count[val] += 1;
    if (count[val] == 1) unq += 1;
}

void remove(int val, int &unq, vector<int> &count) {
    count[val] -= 1;
    if (count[val] == 0) unq -= 1;
}

int solve(int totalUnq, vector<int> &A, vector<int> &count) {
    int len = (int) A.size();
    int answer = len;
    int unq = 0;

    for (int i = 0, hi = -1; i < len; i++) {
        while (hi + 1 < len && unq != totalUnq) {
            hi += 1;
            add(A[hi], unq, count);
        }
        if (unq == totalUnq) {
            answer = min(answer, hi - i + 1);
        }
        remove(A[i], unq, count);
    }

    return answer;
}

int solution(vector<int> &A) {
    int len = (int) A.size();
    int totalUnq = 0;
    vector<int> count(len + 1, 0);

    for (int val: A) {
        count[val] += 1;
        if (count[val] == 1) totalUnq += 1;
    }

    count = vector<int> (len + 1, 0);
    int answer = solve(totalUnq, A, count);
    
    return answer;
}

int main() {
    vector<int> A = {7,3,7,3,1,3,4,1};
    vector<int> B = {2,1,1,3,2,1,1,3};
    vector<int> C = {7,5,2,7,2,7,4,7};
    vector<int> D = {};
    vector<int> E = {1,2,3};
    
    cout << solution(A) << endl;
    cout << solution(B) << endl;
    cout << solution(C) << endl;
    cout << solution(D) << endl;
    cout << solution(E) << endl;
}

