#include<bits/stdc++.h>
using namespace std ;

const int N = (int) 2e6 + 10 ;
const int inf = (int) 2e9 ;

class Helper {
private:
    set<pair<int, int>> values;
public:
	Helper() {
        values.clear();
    }

    void add(int value, int pos) {
        auto it = values.lower_bound({value, -1});

        if (it->first > value && it != values.begin()) it--;
        if (it->first == value) values.erase(it);

        values.insert({value, pos});
    }

    int greaterOrEqual(int value) {
        auto key = values.lower_bound({value, -1});
        if (key == values.end()) return 0;
        return key->second;
    }

    int smallerOrEqual(int value) {
        auto key = values.lower_bound({value, -1});
        if (key == values.end()) key--;

        if (key->first > value) {
            if (key == values.begin()) return 0;
            key--;
        }
        return key->second;
    }
};

class Solution {
public:
	int oddEvenJumps(vector<int>& jump) {
		int n = (int) jump.size();
		int answer = 0;
		vector<vector<int>> can(n + 1, vector<int>(2, 0));

		Helper helper;

		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1) {
				can[i][0] = can[i][1] = 1;
				answer += 1;
				helper.add(jump[i], i);
			} else {
				int greater = helper.greaterOrEqual(jump[i]);
				int smaller = helper.smallerOrEqual(jump[i]);

				if (greater > i) can[i][1] = can[greater][0];
				if (smaller > i) can[i][0] = can[smaller][1];

				answer += (can[i][1]);
				helper.add(jump[i], i);
			}
		}

		return answer;
	}
};

int main(){
   vector<int> arr = {5,1,3,4,2};
   Solution sln;
   cout << sln.oddEvenJumps(arr) << endl;
   return 0 ;
}
