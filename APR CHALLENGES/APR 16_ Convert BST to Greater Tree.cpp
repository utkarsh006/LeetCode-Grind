class Solution {
public:
    void greatersum(TreeNode* root, int &sum)
    {
        if(root==NULL) return;
        
        greatersum(root->right,sum);     // go to right first
        sum += root->val;               // update sum
        root->val = sum;               // assign sum to curr node
        greatersum(root->left,sum);   // go to left
    }
    TreeNode* convertBST(TreeNode* root) 
    {
        int sum = 0;
        greatersum(root,sum);
        return root;
    }
};
