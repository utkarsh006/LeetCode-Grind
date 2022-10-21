// Explanation:
// Solution 01
// Using Vector.
// Here we’ll do inorder traversal, which is (left subtree → root → right subtree).
// We’ll store the values from the left side in our vector, which will be in increasing order.
// Finally, we’ll return (k-1) element from our vector, as it’s in increasing order so it will be kth smallest element.
// Time complexity: O(n), as we’re traversing the whole tree once.
// Solution 02
// Using Recursion.
// if we do inorder traversal then in kth iteration we’ll get our ans.
// return the ans.
// Time complexity: O(n).
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
//solution-01
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
         vector<int> a;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        int ans = a[k-1];
        return ans;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
};
//solution-02
class Solution {
public:
    int ans;
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
    
    void inorder(TreeNode* root, int& k) {
        if (!root) return;
        inorder(root->left, k);
        if (--k == 0){
            ans = root->val;
            return;
        } 
        inorder(root->right, k);
    }  
};