/* Problem : Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example: 
    Input: nums = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: [0,-10,5,null,-3,null,9] is also accepted

    Input: nums = [1,3]
    Output: [3,1]
    Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
*/

/*
Approach : 

-- Find the mid of the array and make that node as root node.
-- Now array is divided into two parts , one of elements before mid and other elements after mid.
-- Now keep calling recursion for the both parts until start is not greater than end.
--Atlast return root as it will contain whole tree.

*/

/*
Algorithm :

1. Initialize the start and end of array to 0 and nums.size()-1 respectively.

2. Now use recursion and pass nums, start,end as arguments.

3. If start> end then return NULL.

4. Find the mid of the array and create a root node with nums[mid] value.

5. Add elements in the root->left by calling the recrusion which will find the mid of elements from start to mid-1.

6. Same way add elements in the root->right by calling the recrusion which will find the mid of elements from mid+1 to end.

7. Atlast return node.
*/

class Solution {
public:
    
    TreeNode* createTree(vector<int>& nums,int start,int end)
    {
            if(start>end) return 0;
            int mid=(start+end)/2;
            TreeNode* root= new TreeNode(nums[mid]);
            root->left= createTree(nums,start,mid-1);
            root->right=createTree(nums,mid+1,end);
             return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        return createTree(nums,start,end);
    }
};

/*
Time Complexity: O(N logN) we are traversing the whole array along with finding mid(binary search concept that's why logn)
Space Complexity: O(N) Recursion Stack Space
*/