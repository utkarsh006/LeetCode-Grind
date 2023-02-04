/* Problem :
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that 
every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
As a reminder, a binary search tree is a tree that satisfies these constraints:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

/* Approach :
1. The right-most node in the tree represents the maximum value because the input is a BST. 
2. So, after processing the tree's right-most node, we go left in a recursive fashion.
3. That is, recursively [Go right] followed by [Process node] and [Go left]. (Inorder Traversal in Reverse)
4. We must update the current node's val to the curr sum (node->val=curr sum) and 
5. add the current node's val to the curr sum while processing each node.
6. Return to the tree's root after completing the entire journey.
*/

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

/*
Time Complexity - O(n) [As each node is traversed exactly once]
Space Complexity - O(n) [For recursion stack]
*/
