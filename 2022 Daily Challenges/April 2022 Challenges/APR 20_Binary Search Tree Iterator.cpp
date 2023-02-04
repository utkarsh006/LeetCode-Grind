/* Problem : Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called. */
 
//Approach 1

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    pushLeftsUntilNull(root);
  }

  int next() {
    TreeNode* root = stack.top();
    stack.pop();
    pushLeftsUntilNull(root->right);
    return root->val;
  }

  bool hasNext() {
    return !stack.empty();
  }

 private:
  stack<TreeNode*> stack;

  void pushLeftsUntilNull(TreeNode* root) {
    while (root) {
      stack.push(root);
      root = root->left;
    }
  }
};

Time: Constructor: O(h), next(): O(h)
Space: O(h)

// Approach 2
 
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 
class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    inorder(root);
  }

  /** @return the next smallest number */
  int next() {
    return vals[i++];
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return i < vals.size();
  }

 private:
  int i = 0;
  vector<int> vals;

  void inorder(TreeNode* root) {
    if (!root)
      return;

    inorder(root->left);
    vals.push_back(root->val);
    inorder(root->right);
  }
};


