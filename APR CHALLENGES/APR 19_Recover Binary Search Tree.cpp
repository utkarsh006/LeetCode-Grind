class Solution {
    TreeNode* first, *last, *prev;
public:
    // the idea is the in-order BST is always increasing, if not, then there is something wrong
    void inorder(TreeNode* root){
        if(root==NULL) return;
        // track left side to start with min
        inorder(root->left);
        if(prev!=NULL && (root->val<prev->val)){
            if(first==NULL){
                first=prev;
                last=root;
            }
            else
                last=root;
        }
        // update the previous node
        prev=root;
        // check the right side
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=prev=NULL;
        inorder(root);
        // swap the two wrong ones
        swap(first->val,last->val);
    }
};
