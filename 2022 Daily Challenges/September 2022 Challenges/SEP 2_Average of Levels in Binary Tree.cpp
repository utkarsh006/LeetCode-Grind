/* Problem : Average of Levels in Binary Tree

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
Answers within 10-5 of the actual answer will be accepted.
*/


/* Approach :
1. The plan is to use BFS, which is a popular method for traversing the tree level by level.
2. We can use queue to place the first root node in a queue for a conventional BFS.
3. After that, remove the front of the line and move its offspring to the back of the queue.
4. Repeat the preceding steps until the line is empty.
5. In this question, we must also determine the average value of the nodes on each level. T
o save the current sum of the nodes, we may simply use sum.
7. After analyzing all of the nodes on each level, compute the average.

*/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> answer;
        while(!q.empty())
        {
            int n = q.size();
            double sum = 0;
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            answer.push_back(sum / n);
        }
        return answer;
    }
};


/*
Time Complexity: O(N) where N is the number of nodes in the tree
Space Complexity: O(M) where M is the maximum number in the tree at any level
*/
