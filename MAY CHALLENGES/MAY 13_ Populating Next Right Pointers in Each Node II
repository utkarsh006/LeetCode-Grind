class Solution {
public:
    Node* connect(Node* root) 
    {
        if (!root) return root;
         queue<Node*> q;
         q.push(root); q.push(NULL);
        
        while (q.size() > 1)
        {
            Node* curr = q.front();
            q.pop();
            if (!curr)
            {
                q.push(NULL);
                continue;
            }
            curr->next = q.front();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return root;
    }
};
