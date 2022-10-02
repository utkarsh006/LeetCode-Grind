/* Intuition:

1. Firstly we will traverse in PreOrder manner.
2. Keep a maxi variable passing in the recursion calls except for the parent node
3. If at any time the current node value is >= the maxi seen so far then just update the maxi and increase the counter.   */

class Solution {
public:
    int ans=0;
    void pre(TreeNode* root,int maxi)
    {
        if(!root) return;
        if(root->val>=maxi)
        {
            ans++;
            maxi = root->val;
        }
        pre(root->left,maxi);
        pre(root->right,maxi);
    }
    int goodNodes(TreeNode* root)
    {
        pre(root,INT_MIN);
        return ans;
    }
};