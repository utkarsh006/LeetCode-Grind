
// 623. Add One Row to Tree
//  link to problem statement :- https://leetcode.com/problems/add-one-row-to-tree/

/*
1. If the given depth is 1, then simply create a new node with value val and assign it as the root node and add
   the original tree towards its left.
2. Else, apply BFS traversal.
3. Add the root node to the queue.
4. Untill the queue isn't empty remove an element from it and if its childern isn't NULL then add them to the queue.
5. If we have reached a depth equals to given depth-1, then store the left subtree and right subtree of the currentNode
   in two variables(say treeLeft & treeRight respectively).
6. Now create two new node with value val and add them to the left and right of the currentNode.
7. Now add the treeLeft to the left to the new node & treeRight to the right of the other node.

Time Complexity = O(n), since in the worst case we'll have to traverse the entire tree
Space Complexity = O(m), m->size of the queue

*/

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
class Solution
{
public:
    TreeNode *addRow(TreeNode *&root, int val, int depth)
    {
        queue<TreeNode *> q;
        q.push(root);
        int currentLevel = 1;

        while (!q.empty())
        {
            if (currentLevel == depth - 1)
            {
                while (!q.empty())
                {
                    TreeNode *currentNode = q.front();
                    q.pop();

                    TreeNode *treeLeft = currentNode->left;
                    TreeNode *treeRight = currentNode->right;

                    currentNode->left = new TreeNode(val);
                    currentNode->right = new TreeNode(val);

                    currentNode->left->left = treeLeft;
                    currentNode->right->right = treeRight;
                }
                return root;
            }

            else
            {
                int len = q.size();
                while (len--)
                {
                    TreeNode *currentNode = q.front();
                    q.pop();

                    if (currentNode->left != NULL)
                        q.push(currentNode->left);
                    if (currentNode->right != NULL)
                        q.push(currentNode->right);
                }
                currentLevel++;
            }
        }
        return root;
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *org = root;
            root = new TreeNode(val);
            root->left = org;
        }

        else
            root = addRow(root, val, depth);

        return root;
    }
};