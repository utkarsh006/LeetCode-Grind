class Solution {
    
    void dfs(TreeNode* org, TreeNode* copy, TreeNode* target, TreeNode*& ans) 
    {
        if(!org) return;
        
        if(org == target) 
            ans = copy;
        
        
        dfs(org->left, copy->left, target, ans);
        dfs(org->right, copy->right, target, ans);
        
        return;
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        TreeNode* ans = NULL;
        dfs(original, cloned, target, ans);
        return ans;
    }
};
