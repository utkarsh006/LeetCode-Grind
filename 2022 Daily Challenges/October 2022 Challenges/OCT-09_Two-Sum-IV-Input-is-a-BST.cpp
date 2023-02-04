

//653. Two Sum IV - Input is a BST

//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

/*
Intuition :- Store the inorder traversal of the given BST in a vector.Now check if there exists two values whose sum is equal to k then return true.Else return false;.
1.Time Complexity = O(N),for performing the inorder traversal
2.Space complexity = O(N),for storing the inorder traversal
3.Recursive stack space = O(h)
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
    
    void dfs(TreeNode* root,vector<int>&inorder)
    {
        if(root == NULL)
            return;
        
        dfs(root->left,inorder);
        inorder.push_back(root->val);
        dfs(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k)
    {
        vector<int>inorder;
        dfs(root,inorder);
        
        int start = 0;
        int end = inorder.size()-1;
        while(start < end)
        {
            if(inorder[start]+inorder[end] == k)
                return true;
            
            else if(inorder[start]+inorder[end] > k)
                end --;
            else
                start ++;
        }
    return false;
    }
};
