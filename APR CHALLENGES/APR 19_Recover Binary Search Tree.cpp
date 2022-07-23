/* Problem :
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
 */

 /* Approach :
 In a BST the result of traversing in order should be arranged in increasing order.
 Thus to identify which nodes are in the wrong position we simply check when two consecutive nodes are not arranged in increasing order.
 */

 /* Steps :
1. traverse the tree in order.
2. identify which nodes are in the wrong position.
3. swap the wrong nodes.
 */

 class Solution
 {
    TreeNode* first, *last, *prev;
public:
    // the idea is the in-order BST is always increasing, if not, then there is something wrong
    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        // track left side to start with min
        inorder(root->left);
        if(prev!=NULL && (root->val<prev->val))
            {
            if(first==NULL){
                first=prev;
                last=root;
            }
            else
                last=root;
        }
        // update the previous node
        prev=root;
        // check the right side
        inorder(root->right);
    }
    void recoverTree(TreeNode* root)
    {
        first=last=prev=NULL;
        inorder(root);
        // swap the two wrong ones
        swap(first->val,last->val);
    }
};

 /* Time and Space Complexity :
 Time Complexity O(N)--> For In order traversal
 Space O(1)
 */
