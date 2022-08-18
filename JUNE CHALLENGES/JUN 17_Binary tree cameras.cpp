// Binary Tree Cameras

/* Problem :
You are given the root of a binary tree.
We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
Return the minimum number of cameras needed to monitor all nodes of the tree.
*/

/* Approach :
We begin putting cameras at the bottom and work our way up to the tree's root node.
In this case, we'll use the nodes' 0, 1, and 2 variables. where:
0 -> Installing a camera is required for this node (0 Cam monitor it).
1 -> Camera is not needed for this node (1 Cam monitor it).
2 -> This already has a camera installed (Cam fix here which monitor parent node and child nodes).

According to intuition, we will start installing cameras on the parent of the leaf node
and as we approach the tree's leaf nodes, with a goal of having each camera cover a maximum of two leaf nodes.
*/

class Solution {
 public:
  int minCameraCover(TreeNode* root) {
    vector<int> ans = dfs(root);
    return min(ans[1], ans[2]);
  }

 private:
  // 0 := all nodes below root are covered except root
  // 1 := all nodes below and including root are covered w/o camera here
  // 2 := all nodes below and including root are covered w/ camera here
  vector<int> dfs(TreeNode* root) {
    if (!root)
      return {0, 0, 1000};

    vector<int> l = dfs(root->left);
    vector<int> r = dfs(root->right);

    const int s0 = l[1] + r[1];
    const int s1 = min(l[2] + min(r[1], r[2]),
                       r[2] + min(l[1], l[2]));
    const int s2 = 1 + min({l[0], l[1], l[2]}) +
                       min({r[0], r[1], r[2]});

    return {s0, s1, s2};
  }
};



/* Complexities:
Time Complexity: O(N), DFS traversal
Space Complexity: O(N), Auxiliary recursion stack space
*/

