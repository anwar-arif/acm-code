class Solution {
public:
    const int ALPHA = 52;
	vector<int> required;

	int id(char ch) {
		if (ch >= 'A' && ch <= 'Z') return 26 + (ch - 'A');
		return (ch - 'a');
	}

	bool valid(vector<int> &found) {
		for (int i = 0; i < ALPHA; i++) {
			if (required[i] > found[i]) return false;
		}
		return true;
	}

	string minWindow(string s, string t) {
		vector<int> found(ALPHA);
		required.assign(ALPHA, false);

		for (char ch: t) {
			required[id(ch)] += 1;
		}

        int len = (int) s.size(), answer = len + 1, start = 0;
        for (int i = 0, hi = -1; i < len; i++) {
            while (hi + 1 < len && !valid(found)) {
                hi += 1;
                found[id(s[hi])] += 1;
            }

            if (valid(found)) {
                if (answer > (hi - i + 1)) {
                    answer = hi - i + 1;
                    start = i;
                }
            }
            found[id(s[i])] -= 1;
        }

        return (answer > len) ? "" : s.substr(start, answer);
    }
};
