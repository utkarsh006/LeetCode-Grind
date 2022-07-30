class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverseLeft(root);
    }
    
    bool hasNext() {
        return !empty(stk_);
    }
    
    int next() {
        TreeNode *node = stk_.back(); stk_.pop_back();
        traverseLeft(node->right);
        return node->val;
    }

private:
    void traverseLeft(TreeNode *node) {
        for (; node != nullptr; node = node->left) {
            stk_.emplace_back(node);
        }
    }

    vector<TreeNode *> stk_;
};