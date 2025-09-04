class Solution {
    vector<int> getLeftBoundary(TreeNode *root) {
        TreeNode *cur = root->left;

        vector<int> leftBoundary;
        while (cur != NULL) {
            leftBoundary.push_back(cur->val);
            if (cur->left) cur = cur->left;
            else if (cur->right) cur = cur->right;
            else break;
        }

        if (leftBoundary.size()) leftBoundary.pop_back();
        return leftBoundary;
    }

    vector<int> getRightBoundary(TreeNode *root) {
        TreeNode *cur = root->right;

        vector<int> boundary;
        while (cur != NULL) {
            boundary.push_back(cur->val);
            if (cur->right) cur = cur->right;
            else if (cur->left) cur = cur->left;
            else break;
        }

        if (boundary.size()) boundary.pop_back();
        return boundary;
    }

    void getChilds(TreeNode *root, vector<int> &childs) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            childs.push_back(root->val);
        }
        getChilds(root->left, childs);
        getChilds(root->right, childs);
    }

    public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == NULL) return {};
        if (root->left == NULL && root->right == NULL) return {root->val};

        auto leftBoundary = getLeftBoundary(root); 

        auto rightBoundary = getRightBoundary(root);
        reverse(rightBoundary.begin(), rightBoundary.end());

        vector<int> childs;
        getChilds(root, childs);

        vector<int> res;
        res.push_back(root->val);
        for (auto val: leftBoundary) res.push_back(val);
        for (auto val: childs) res.push_back(val);
        for (auto val: rightBoundary) res.push_back(val);

        return res;
    }
};
