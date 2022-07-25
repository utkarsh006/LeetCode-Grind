/* Problem
Given the root of a binary tree, return the sum of values of its deepest leaves.
*/

/* Approach
Simple tree traversals (BFS and DFS) can be used to fix the issue with ease.
Simply reset the sum appropriately (when a new depth is reached),
then add up to the sum (when current depth is the maximum reached till now).
*/

//Using BFS Traversal
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty())
        {   // breadth = number of nodes at the current level
            int breadth = q.size();
            sum = 0;
            for(int i = 0; i<breadth; i++)
            {
                TreeNode* front = q.front(); q.pop();
                //at each level update the sum
                sum += front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
        return sum;
    }
/*
Time Complexity : O(N), where, N is the total number of nodes in the given Tree.
Space Complexity : O(N)
*/


//DFS Traversal
		int depth = 0, sum = 0;
    int deepestLeavesSum(TreeNode* root, int curr_depth = 0) {

        if(!root) return 0;
        // if current root is a left
        if(!root->left && !root->right)
            // if current depth is the deepest them add current root value to sum
            if(curr_depth == depth) sum += root->val;
            // if found more deeper node then update the sum
            else if(curr_depth > depth){ sum = root->val; depth = curr_depth;}

        deepestLeavesSum(root->left, curr_depth + 1);
        deepestLeavesSum(root->right, curr_depth + 1);
        return sum;
}

/*
Time Complexity : O(N), where, N is the total number of nodes in the given Tree.
Space Complexity : O(N)
*/
