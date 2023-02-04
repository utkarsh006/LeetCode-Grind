/*
Problem:
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Example:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
*/


/*
##Approach -1:  Iterative Method

1. Firstly we'll make another pointer (say curr) and will assign root to curr.

2. Then we'll start traversing the tree with curr

3. So we'll run a while loop which will always be true , so that until we don't get a position to insert our node we keep on traversing

4. If the value of current node(curr->val) is less than the value of node to be inserted (val) then we'll move our curr to the right of the tree , but here first we'll check before moving 
            -- if curr->right is not NULL then we will move curr to it's right
            -- else we'll make a new node with the val & will link the curr->right to that node and break out of it so that while loop doesn't move forward

5. Same way we'll check if value of current node(curr->val) is greater than the value of node to be inserted (val) then we'll move our curr to the left of the tree & will check the same conditions
            --if curr->left is not NULL then we will move curr to it's left
            --else we'll make a new node with the val & will link the curr->left to that node and break out of it so that while loop doesn't move forward

6. Base Case: if root is NULL then we will simply make a new node & will return that node because that's the only node in a tree
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        if(!root)
        {
            TreeNode* node=new TreeNode(val);
            return node;
        }
        while(true)
        {
            if(curr->val < val)
                
                if(curr->right!=0)curr=curr->right;
                else 
                {
                    TreeNode* node=new TreeNode(val);
                    curr->right=node;
                    break;
                }
            else
            {
                if(curr->left!=0) curr=curr->left;
                else
                {
                    TreeNode* node=new TreeNode(val);
                    curr->left=node;
                    break;
                }
            }
        }
        // as root contains whole tree so will return root.
        return root;
    }
};

/*
Time Complexity: O(N)   N is height of tree
Space Complexity: O(1)
*/



/*
##Approach -2:  Recursive Method 

        Logic is same,only recursion is used
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val > val) root->left= insertIntoBST(root->left,val);
        else root->right= insertIntoBST(root->right,val);
        return root;
    }
};

/*
Time Complexity: O(N)   N is height of tree
Space Complexity: O(H)  It is recursion stack space
*/