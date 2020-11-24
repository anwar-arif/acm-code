#include<bits/stdc++.h>
using namespace std;

class TrieTree {
private:
    struct Node {
        bool isEnd;
        int prefix;
        vector<Node*> child;
        Node() {
            child.resize(26);
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            isEnd = false;
            prefix = 0;
        }
    };

    Node* head;

public:
    TrieTree() {
        head = new Node();
    }

    void add(string s) {
        Node* cur = head;
        cur->prefix++;

        int len = (int) s.size();
        for (int i = 0; i < len; i++) {
            int id = s[i] - 'a';
            if (cur->child[id] == NULL) {
                cur->child[id] = new Node();
            }
            cur = cur->child[id];
            cur->prefix++;
        }
        cur->isEnd = true;
    }

    bool search(string s) {
        Node* cur = head;
        int len = (int) s.size();

        for (int i = 0; i < len; i++) {
            int id = s[i] - 'a';
            if (cur->child[id] == NULL) {
                return false;
            }
            cur = cur->child[id];
        }
        return cur->isEnd;
    }

    int countPrefix(string s) {
        Node* cur = head;
        int len = (int) s.size();

        for (int i = 0; i < len; i++) {
            int id = s[i] - 'a';
            if (cur->child[id] == NULL) {
                return 0;
            }
            cur = cur->child[id];
        }
        return cur->prefix;
    }
};

int main() {
    TrieTree trie;
    for (int i = 0; i < 5; i++) {
        cout << "Enter string: " << endl;
        string str; cin >> str;
        trie.add(str);
        cout << trie.countPrefix(str) << endl;
    }
    return 0;
}
