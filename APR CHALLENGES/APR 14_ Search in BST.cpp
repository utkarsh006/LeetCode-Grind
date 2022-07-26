/* Problem
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
*/

/* Approach :
1. Comparing the element to the tree's root.
2. Return the location of the node if the item matches.
3. If item is smaller than the element already existing at the root, shift to the left sub-tree otherwise.
4. If not, proceed to the appropriate sub-tree.
5. Recursively repeat this process until a match is identified.
6. If the element cannot be located, return NULL.
*/

// 1. Iterative approach:
class Solution
{
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        while (root != nullptr && root->val != val)
        {
               if (root->val > val) 
                  root = root->left;
               else
                   root = root->right;
        }
    return root;
}
};

/*
Time complexity: O(h) where 'h' is the height of the BST. Worst case complexity is O(n) where 'n' is the total number of nodes in the BST.
Space complexity: O(1). This is because there is only one stack frame for the call.
*/


// 2. Recursive approach:
class Solution
{
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if(root==NULL) return root;
        if(root!=NULL && root->val == val) return root;
        if(root->val > val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
    }
};

/*
Time complexity: Same as above for iterative approach.
Space complexity: O(h) where 'h' is the height or depth of the BST.
*/
