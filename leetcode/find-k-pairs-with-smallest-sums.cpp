#include<bits/stdc++.h>
using namespace std;

class Solution {
struct data {
	int firstNum, secondNum, secondIdx;
	data(){}
	data(int a, int b, int c) {
		firstNum = a, secondNum = b, secondIdx = c;
	}

	bool operator < (const data &other) const {
		return firstNum + secondNum > other.firstNum + other.secondNum;
	}
};

public:
    vector<vector<int>> kSmallestPairs(vector<int>& first, vector<int>& second, int k) {
    	vector<vector<int>> answer;
		int lenf = (int) first.size();
		int lens = (int) second.size();

		priority_queue<data> pq;
		for (int i = 0; i < lenf; i++) {
			pq.push(data(first[i], second[0], 0));
		}
		while (k-- && !pq.empty()) {
			auto top = pq.top(); pq.pop();
			answer.push_back({top.firstNum, top.secondNum});
			if (top.secondIdx + 1 < lens) {
				pq.push(data(top.firstNum, second[top.secondIdx + 1], top.secondIdx + 1));
			}
		}

		return answer;
	}
};

int main() {
    Solution sln;
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    int k = 3;

    auto answer = sln.kSmallestPairs(nums1, nums2, k);
    for (auto p: answer) {
        cout << p[0] << " " << p[1] << endl;
    }
}
