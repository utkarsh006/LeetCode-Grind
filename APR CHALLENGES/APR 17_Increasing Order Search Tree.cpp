// Time Complexity: O(N)   Space Complexity:O(N)

class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v)
    {
        if(!root) return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root)
    {
        vector<int>v;
        inorder(root,v);
        TreeNode* ans=new TreeNode(0); TreeNode* node=ans;
        for(int i=0;i<v.size();i++)
        {
            node->right=new TreeNode(v[i]);
            node=node->right;
        }
        return ans->right;
    }
};

// Optimized Approach
// Time Complexity: O(N)   Space Complexity:O(H)
class Solution {
public:
    void helper(TreeNode* root,TreeNode* &dummy)
    {
        if(!root) return;
        
        helper(root->left,dummy);
        root->left=0;
        dummy->right=root;
        dummy=root;
        helper(root->right,dummy);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy= new TreeNode(0);
        TreeNode* ans=dummy;
        helper(root,dummy);
        return ans->right;
    }
};