/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> m;
    void help(TreeNode* root)
    {
        if(root == NULL) return;
        m[root->val]++;
        help(root->left);
        help(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        help(root);
        for(auto i:m)
        {
            if(k-i.first != i.first && m.find(k-i.first) != m.end()) return true;
            else if(k-i.first == i.first && m[i.first] > 1) return true;
        }
        return false;
    }
};
