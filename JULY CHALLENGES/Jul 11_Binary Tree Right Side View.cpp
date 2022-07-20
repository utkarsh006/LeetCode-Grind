class Solution {
public:
    void func(TreeNode* root, int level, vector<int>& ans)
    {
        if(root==NULL) return;
        
        if(ans.size()==level) ans.push_back(root->val);
        
        func(root->right,level+1,ans);
        func(root->left,level+1,ans);
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        func(root,0,ans);
        return ans;
        
    }
};
