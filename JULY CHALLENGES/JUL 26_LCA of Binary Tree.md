## Problem Statement 

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has 
both p and q as descendants (where we allow a node to be a descendant of itself).”

### Example 1

![image](https://user-images.githubusercontent.com/75883328/180924476-28c9dbf1-ccee-450e-bf2e-3d2be6e50ff0.png)

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1

Output: 3

Explanation: The LCA of nodes 5 and 1 is 3.

### Example 2

![image](https://user-images.githubusercontent.com/75883328/180924548-ccaff17c-3d95-46fc-9459-c4af03482993.png)


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4

Output: 5

Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

### Example 3:

Input: root = [1,2], p = 1, q = 2

Output: 1

## Intuition :- 

**Case 1** :- if we get an answer from the left subtree as well as from the right subtree ,then their parent are the LCA i.e. return the root node.

**Case 2** :-  if we get an answer only from the left subtree and null from the right subtree , then return that node as the answer.
=>it is because of the reason that if we haven't got any answer from the right subtree then it indicates that both p & q are in the left subtree.So we'll return that node which we'll find first.

**Case 3** :-  if we get an answer only from the right subtree and null from the left subtree , then return that node as the answer.
=>it is because of the reason that if we haven't got any answer from the left subtree then it indicates that both p & q are in the right subtree.So we'll return that node which we'll find first.

leftAns                  rightAns                 return
not null                 not null                  root
null                     not null                 rightAns
not null                 null                      leftAns
null                     null                      null
 
 
 ## Code
 
 ```cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* LCA(TreeNode* root,TreeNode* x, TreeNode* y)
    {
        
        if(root == NULL)
            return NULL;
        
        if(root == x)
            return x;
        
        if(root == y)
            return y;
        
        
        TreeNode* leftAns = LCA(root->left,x,y);
        TreeNode* rightAns = LCA(root->right,x,y);
        
        //case 1
        if(leftAns !=NULL && rightAns != NULL)
            return root;
        
        //case 2
        if(leftAns != NULL)
            return leftAns;
        
        //case 3
        else
            return rightAns;
            
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        
        return LCA(root,p,q);
    }
};



```
 
 
 
 - Time Complexity = O(n)
 
 - Space Complexity = O(1)
 
 - Recursive Stack Space = O(h),h is the height of the Binary Tree
 
