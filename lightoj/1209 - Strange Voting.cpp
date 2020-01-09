#include<bits/stdc++.h>
using namespace std;

const int N = (int) 500 + 10;
const int inf = (int) 2e9;

struct Vote {
    int who, like, dislike;
    Vote(){}
    Vote(int who, int like, int dislike):
        who(who), like(like), dislike(dislike) {}
}v[N];

vector <int> adj[N];
int match[N], vis[N], male, female, votes;
char a[11], b[11];

void init() {
    for (int i = 0; i < N; i++) {
        adj[i].clear();
    }
}

bool dfs(int u) {
    for (int v: adj[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm() {
    int answer = 0;
    memset(match, -1, sizeof(match));

    for (int i = 1; i <= votes; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) {
            answer += 1;
        }
    }
    return answer;
}

int main() {
//    freopen("in.txt", "r", stdin);
    int T, cas = 0; scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &male, &female, &votes);
        init();

        for (int i = 1; i <= votes; i++) {
            scanf("%s %s", &a, &b);
            int who, like = 0, dislike = 0, len;
            who = (a[0] == 'M') ? 1 : 0;

            len = (int) strlen(a);
            for (int j = 1; j < len; j++) {
                like = like * 10 + (a[j] - '0');
            }

            len = (int) strlen(b);
            for (int j = 1; j < len; j++) {
                dislike = dislike * 10 + (b[j] - '0');
            }

            v[i] = Vote(who, like, dislike);
        }

        for (int i = 1; i <= votes; i++) {
            for (int j = i + 1; j <= votes; j++) {
                if (v[i].who + v[j].who == 1) {
                    if (v[i].like == v[j].dislike || v[i].dislike == v[j].like) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }

        int answer = bpm();
        printf("Case %d: %d\n", ++cas, votes - answer / 2);
    }
    return 0;
}
