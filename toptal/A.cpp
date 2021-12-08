#include<bits/stdc++.h>
using namespace std;

int findGroup(string &str) {
    int num = 0;
    int len = (int) str.size();
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            int j = i;
            while (j < len && str[j] >= '0' && str[j] <= '9') {
                num = (num * 10) + (str[j] - '0');
                j += 1;
            }
            return num;
        }
    }
    return 0;
}

int isOkay(string &str) {
    return str == "OK";
}

int solution(vector<string> &T, vector<string> &R) {
    int len = (int) T.size();
    vector<int> group_size(len + 1, 0), okay_count(len + 1, 0);
    for (int i = 0; i < len; i++) {
        int groupId = findGroup(T[i]);
        group_size[groupId]++;
        okay_count[groupId] += isOkay(R[i]);
    }

    int groupPassed = 0;
    int totalGroup = 0;
    for (int i = 0; i <= len; i++) {
        if (group_size[i] == 0) continue;
        if (group_size[i] == okay_count[i]) groupPassed += 1;
        totalGroup += 1;
    }

    return (groupPassed * 100) / totalGroup;
}


int main() {
    vector<string> T = {"test1a", "test2", "test1b", "test1c", "test3"};
    vector<string> R = {"Wrong Answer", "OK", "OK", "Wrong Answer", "OK"};

    cout << solution(T, R) << endl;
}