//112. Path Sum
//link of ps :- https://leetcode.com/problems/path-sum/

/*
Intuition :- 
1. At every recursive call keep decreasing the targetSum by the value of root.
2. If we have reached the leaf node and the value of targetSum equals to the value of that node then return true,else return false.
3. At last return the OR of the left and right recursive calls.
NOTE :- if root==null return false

Time Complexity = O(n), Since we are iterating over all n-nodes

Space Complexity = O(1), since we are not using any extra space
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
    
    bool isPossible(TreeNode* root,int targetSum)
    {
        if(root->left == NULL && root->right == NULL && targetSum == root->val)
            return true;
        
        if(root->left == NULL && root->right == NULL && targetSum != root->val)
            return false;
        
        bool L = false;
        bool R = false;
        if(root->left != NULL)
            L = isPossible(root->left,targetSum - root->val);
        
        if(root->right != NULL)
            R = isPossible(root->right,targetSum - root->val);
        
    return L || R;
    }
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(root == NULL) return false;
        
        else
            return isPossible(root,targetSum);
    }
};
