//701. Insert into a Binary Search Tree
//link of ps :- https://leetcode.com/problems/insert-into-a-binary-search-tree/

/*
The main logic for the problem is at every node we check to make sure it's bigger or smaller than the value we are trying to insert. If the value is bigger we go right...otherwise we go left. What's really important to understand is we are also verifying the node will be valid when we insert it...as we traverse down the tree we are checking all the nodes along the eventual path the node will take..

Time Complexity = log(n)
Space Complexity = O(1)
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
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};