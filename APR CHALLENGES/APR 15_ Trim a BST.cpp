/* Problem :

*/

/* Approach :
Only nodes in the supplied range from low to high should be included in our binary search tree.

1. Making a recursive function, we'll determine which nodes should be returned in post-order.

2. Therefore, if my current node value in a binary search tree is less than low, 
we may ignore the left subtree (a property of binary search trees: the left subtree of a node only includes nodes with values lower than the node's key).

3. Similar to this, we can disregard the right subtree if my current node value is higher than high 
(a characteristic of a binary search tree is that the right subtree of a node only includes nodes with values higher than the node's key).

4. if the range of our current node value is inside it.
The current node can then be returned. Its left and right subtrees have previously been figured out.
*/

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

/*
Time Complexity : O(N)
Space Complexity : Recursive stack space
*/
