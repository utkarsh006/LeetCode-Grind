class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        //make the queue and push the root
        queue<TreeNode*>q;
        q.push(root);
        
            while(!q.empty())
            {
                vector<int> level;
                int n = q.size();
                
                   for(int i=0; i<n ; i++)
                   {
                      TreeNode* node = q.front();
                      q.pop();
                       
                      if(node->left!=NULL) q.push(node->left);
                      if(node->right!=NULL)q.push(node->right);
                      level.push_back(node->val);
                   }
                ans.push_back(level);
            }
        return ans;
    }
};
