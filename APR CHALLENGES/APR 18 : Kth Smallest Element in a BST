class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) 
    {
        if(root==NULL) return 0;
        
        int left = kthSmallest(root->left,k); 
        
        if(left) return left;        // if we get answer from left call then return it
        k--;
        if(k==0) return root->val;                 // this is kth smallest element
         
        int right=kthSmallest(root->right,k); 
        
        if(right) return right;    // if we get answert from right call than return it
        
        return 0;                           
    }     
};
