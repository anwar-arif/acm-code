#include<bits/stdc++.h>
using namespace std;

/* Segment tree to find sum of numbers between indexes L to R*/
class SegTree {
private:
    int N;
    vector<int> tree;
public:
    SegTree(int _nodes) {
        N = _nodes;
        tree = vector<int>(3 * N, 0);
    }

    void update(int node, int left, int right, int qLeft, int qRight, int value) {
        if (left > qRight || right < qLeft) return;
        if (left >= qLeft && right <= qRight) {
            tree[node] = value;
            return;
        }

        int leftChild = 2 * node, rightChild = leftChild + 1, mid = (left + right) / 2;

        update(leftChild, left, mid, qLeft, qRight, value);
        update(rightChild, mid + 1, right, qLeft, qRight, value);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    void update(int index, int value) {
        update(1, 1, N, index, index, value);
    }

    int query(int node, int left, int right, int qLeft, int qRight) {
        if (left > qRight || right < qLeft) return 0;
        if (left >= qLeft && right <= qRight) return tree[node];

        int leftChild = 2 * node, rightChild = leftChild + 1, mid = (left + right) / 2;

        int leftSum = query(leftChild, left, mid, qLeft, qRight);
        int rightSum = query(rightChild, mid + 1, right, qLeft, qRight);

        return (leftSum + rightSum);
    }

    int query(int left, int right) {
        return query(1, 1, N, left, right);
    }
};

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6};
    SegTree segTree(6);

    for (int i = 1; i <= 6; i++) {
        segTree.update(i, arr[i]);
    }

    for (int i = 1; ; i++) {
        cout << "Enter range: ";

        int left, right;
        cin >> left >> right;

        if (left == -1 && right == -1) break;
        cout << segTree.query(left, right) << endl;
    }
    return 0;
}

/* Complexity: nlog(n) */
