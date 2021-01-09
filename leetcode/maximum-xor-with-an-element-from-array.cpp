/**
 * @file maximum-xor-with-an-element-from-array
 * @author Anwar Hossain <anwararif727@gmail.com>
 *
 * @date Wednesday December 30 2020
 *
 * @brief 
 */

class Solution {
public:
	const int M = 30;

	vector<vector<int>> trie;

	struct Query {
		int value, limit, id;
		Query() {}
		Query(int value, int limit, int id) :
			value(value), limit(limit), id(id) {}
		bool operator < (const Query &other) const {
			return limit < other.limit;
		}
	};

	int nodeId = 0;

	int newNode() {
		trie[nodeId][0] = trie[nodeId][1] = -1;
		return nodeId++;
	}

	void insert(int value) {
		int current = 0;
		for (int i = M; i >= 0; i--) {
			int bit = (value & (1 << i)) ? 1 : 0;
			if (trie[current][bit] == -1) {
				trie[current][bit] = newNode();
			}
			current = trie[current][bit];
		}
	}

	int solve(int value, int limit) {
		int answer = 0, current = 0;
		for (int i = M; i >= 0; i--) {
			int bit = (value & (1 << i)) ? 1 : 0;
			if (trie[current][1 - bit] != -1) {
				answer += (1 << i);
				current = trie[current][1 - bit];
			} else if (trie[current][bit] != -1) {
				current = trie[current][bit];
			} else {
				return -1;
			}
		}
		return answer;
	}

	vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
		int N = (int) nums.size() + 10;
		trie.assign(N * M, vector<int> (2, -1));
		vector<Query> query;
		newNode();

		for (int i = 0; i < (int) queries.size(); i++) {
			int value = queries[i][0], limit = queries[i][1];
			query.push_back(Query(value, limit, i));
		}

		sort(query.begin(), query.end());
		sort(nums.begin(), nums.end());
		
		vector<int> answer((int) query.size(), -1);
		for (int i = 0, j = 0; i < (int) query.size(); i++) {
			while (j < (int) nums.size() && nums[j] <= query[i].limit) {
				insert(nums[j++]);
			}
			answer[query[i].id] = solve(query[i].value, query[i].limit);
		}

		return answer;
	}
};
