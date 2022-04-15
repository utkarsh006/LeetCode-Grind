class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if(root==NULL) return root;
        
        if(root->val >= low && root->val <= high)   // CASE 1
        {
            root->left = trimBST(root->left,low,high);
            root->right = trimBST(root->right,low,high);
            return root;
        }
        
// CASE 2
        else if(root->val < low)     return trimBST(root->right,low,high);
// CASE 3
        else if(root->val > high)     return trimBST(root->left,low,high);
        
        return NULL;
    }
};
