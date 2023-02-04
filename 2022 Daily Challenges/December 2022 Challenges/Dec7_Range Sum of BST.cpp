/* As the question says : range is [low, high]. These braces [] means that both low and high are included in the range.
So, our if condition is pretty much clear.
Go recursively to the left and right subtree 
If above if condition is met, just add value of node else skip it and make the calls.   */


class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int H) 
    {
        if(!root) return 0;
        if(root -> val >= L && root -> val <= H)
        {
            return root->val + rangeSumBST(root -> left, L, H) +
                   rangeSumBST(root -> right, L, H);   
        }

        else
        {
            return rangeSumBST(root -> left, L, H) +   
                 rangeSumBST(root -> right, L, H);   
        }
          
                
    }
};

// Time Complexity : O(N), where N is the number of nodes in the given tree
// Space Complexity : O(H), where H is the height of the tree.
