#include<bits/stdc++.h>
using namespace std;

/*
s = "011010", minJump = 2, maxJump = 3
returns true


s = "01101110", minJump = 2, maxJump = 3
returns false
*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int length = (int) s.size();
        if (s[0] == '1' || s[length - 1] == '1') return false;

        queue<int> qu;
        
        for (int i = 0; i < length; i++) {
            int leftMost = i - maxJump;
            int rightMost = i - minJump;

            while (!qu.empty() && qu.front() < leftMost) qu.pop();
            
            bool canPush = false;
            if (s[i] == '0' && i >= minJump) {
                if (qu.empty()) return false;
                if (qu.front() > rightMost) return false;
                canPush = true;
            }
            
            if (i == 0) canPush = true;
            if (s[i] == '0' && canPush) qu.push(i);
        }

        return true;
    }
};

int main() {
    Solution sln;
    string s = "0000000000";
    int minJump = 8, maxJump = 8;
    cout << sln.canReach(s, minJump, maxJump) << endl;
}