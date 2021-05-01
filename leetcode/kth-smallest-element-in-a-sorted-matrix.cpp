#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for (auto rows: matrix) {
            for (auto value: rows) {
                pq.push(value);
                if (pq.size() > k) pq.pop();
            }
		}
		return pq.top();
    }
};

