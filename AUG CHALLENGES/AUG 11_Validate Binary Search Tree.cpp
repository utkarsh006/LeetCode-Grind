/* Problem :
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

/* Explaining The Question :
A Binary Search Tree has been given to us. It could or might not be valid.
It has to be verified.
There will always be a minimum of two nodes.
*/

/* Approach :
1. In essence, what we'll do is move through the Binary Tree in order.
    This implies that the node we visit after it should always be bigger than the one before it.
    If it isn't, we immediately see that the tree is false.

2. Its validity is default. until a node that is smaller than the preceding node is found.

3. In order to maintain track of our previous node during the in-order traverse of the tree, we will define a prior node pointer.

4. We shall traverse the tree in sequence, determining at each stage if the current node is smaller than the preceding node.
If so, the tree cannot be used.

5. If no flawed nodes are discovered, the tree is considered genuine.
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};

/*
Time complexity : O(N) in the worst case when the tree is a BST or the "bad" element is a rightmost leaf.
Space complexity : O(N) for the space on the run-time stack.
*/
