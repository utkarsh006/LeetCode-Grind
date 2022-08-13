/*
Problem:
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both 
p and q as descendants (where we allow a node to be a descendant of itself).

Example:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.


Approach:
The problem can be divided into 3 cases:

Case 1: Both p & q are smaller than the root node:
    Then both elements, as well as LCA, will be in the left subtree.
Case 2: Both p & q  greater than the root node:
    Then both elements, as well as LCA, will be in the right subtree.
Case 3: If 1 element is greater than the root and the other is smaller than the root:
    It means both elements are in different subtrees. That means the root node is the LCA.

Algorithm:

1. Compare p and q with root node 
2. If p and q are greater than root, replace root with its right child
3. If p and q are lesser than root, replace root with its left child
4. Else return root node
5. Repeat the step 1,2,3 until step 4 is reached

*/

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
		int temp = root->val; 
        
        // If both p and q are less than the root value Then go for the left subtree of the root
        if(p->val < temp && q->val < temp)
        {
			 return lowestCommonAncestor(root->left, p, q);
        }
        // If both p and q are greater than the root value Then go for the right subtree of the root
        else if(p->val > temp && q->val > temp)
        {
			return lowestCommonAncestor(root->right, p, q);
        }
        // The present root is the solution;
        else
        {
            return root;
        }
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/