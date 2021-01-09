class Solution {
public:
    int maximumGain(string str, int x, int y) {
        int len = (int) str.size();
        stack<char> cur, other;

        char first = (x > y) ? 'a' : 'b';
        char second = (x > y) ? 'b' : 'a';

        int maxVal = max(x, y), minVal = min(x, y);
        int answer = 0;

        for (auto ch: str) {
            if (!cur.empty() && cur.top() == first && ch == second) {
                answer += maxVal;
                cur.pop();
            } else {
                cur.push(ch);
            }
        }

        while (!cur.empty()) {
            char ch = cur.top(); cur.pop();
            if (!other.empty() && other.top() == first && ch == second) {
                other.pop(), answer += minVal;
            } else {
                other.push(ch);
            }
        }

        return answer;
    }
};
