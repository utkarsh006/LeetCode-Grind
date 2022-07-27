/*

Intuition:-
1. Store the preorder traversal of the given binary tree in a vector.
2. Now traverse that vector and update the right of current Node with the value its next node of the preorder traversal vector, i.e. preorder[i]->right = preorder[i+].
3. Also set the left child of all the node as NULL.

*Time Complexity = O(N) + O(N) = O(2N)
                              = O(N) , for performing preorder traversal + for traversing the preorder vector to update the left and right child of all the nodes
																																															
*Space Complexity = O(N), for storing the preorder traversal

*Recursive Stack Space = O(h),  h = height of the binary tree

*/

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
    
    //function to perform preorder traversal of a binary tree
    void preorderTraversal(TreeNode* root,vector<TreeNode*>&preorder)
    {
        if(root == NULL)
            return;
        
        preorder.push_back(root);
        preorderTraversal(root->left,preorder);
        preorderTraversal(root->right,preorder);
        
        return ;
    }
    
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
            return ;
        
        vector<TreeNode*>preorder;
        
        preorderTraversal(root,preorder);
        
        for(int i=0; i<preorder.size()-1; i++)
        {
            preorder[i]->right = preorder[i+1];
            preorder[i]->left = NULL;
        }
    
        preorder[preorder.size()-1]->right = NULL;
        preorder[preorder.size()-1]->left =  NULL;
    }
};
