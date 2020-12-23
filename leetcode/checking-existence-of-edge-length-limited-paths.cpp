class Solution {
public:
    struct Query {
        int queryId, from, to, howFar;
        Query() {}
        Query(int queryId, int from, int to, int howFar) :
            queryId(queryId), from(from), to(to), howFar(howFar) {}

        bool operator < (const Query &other) {
            return howFar < other.howFar;
        }
    };

    vector<int> parent;

    int findpar(int r) {
        return (parent[r] == r) ? r : parent[r] = findpar(parent[r]);
    }

    void addEdge(int from, int to) {
        from = findpar(from);
        to = findpar(to);
        if (from != to) {
            parent[from] = to;
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        vector<Query> query;

        for (int i = 0; i < (int) queries.size(); i++) {
            int from = queries[i][0];
            int to = queries[i][1];
            int dist = queries[i][2];
            query.push_back(Query(i, from, to, dist));
        }

        sort(query.begin(), query.end());
        sort(edgeList.begin(), edgeList.end(), [&] (vector<int> &me, vector<int> &other) {
            return me[2] < other[2];
        });

        vector<bool> answer((int) queries.size(), false);
        for (int i = 0, j = 0; i < (int) query.size(); i++) {
            while (j < (int) edgeList.size() && edgeList[j][2] < query[i].howFar) {
                int from = edgeList[j][0], to = edgeList[j][1];
                addEdge(from, to);
                j++;
            }
            int from = query[i].from, to = query[i].to, id = query[i].queryId;
            answer[id] = (findpar(from) == findpar(to)) ? true : false;
        }
        return answer;
    }
};