#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int length = (int) S.size(), index = 0;
        char lastChar = '#';
        
        long long count = 0;
        for (int i = 0; i < length && count < K; i++, index++) {
            if (isdigit(S[i])) {
                count *= (S[i] - '0');
            } else {
                count++;
                lastChar = S[i];
            }
        }

        if (K % count == 0) return string(1, lastChar);

        while (index--) {
            if (isdigit(S[index])) {
                count /= (S[index] - '0');
            } else {
                K %= count;
                if (K == 0) return string(1, S[index]);
                count--;
            }
        }

        return "";
    }
};

int main() {
    Solution sln;
    cout << "answer: " << sln.decodeAtIndex("leet2code3", 14) << endl;
}