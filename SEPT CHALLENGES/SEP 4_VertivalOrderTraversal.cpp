/*Problem
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.
*/

/* Approach

We will perform a tree traversal and assign a vertical and level to every node.
Based on this vertical and node, we store the node in our special data structure that we are gonna create.
We are going to use level order traversal, initially we will push the root in the queue and also two more variables one for vertical and the other for level, both intialized with 0.
Whenever we push the left child we are going to decrease the vertical by one and increase level by 1 and in the case of right child we are going to increase both the vertical and level both by 1.
Just iterate over our verticals by using the data structure that we created.
In every iteration, we take a list(to store all nodes of that vertical) and again iterate over the levels. We then push the nodes of the level  and push it to our vertical list.
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto q:mp){
            vector<int> col;
            for(auto p:q.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

/*Time Complexity: O(NlogNlogN*logN)
Space Complexity: O(N)*/