class Solution {
public:
    bool checkvalue(vector<vector<int>>& grid, int x, int y, int n){
        int m = n, val = grid[x][y];
        for(int i = x; i < x + n; i++){
            for(int j = y; j < y + n; j++){
                if(grid[i][j] != val){
                    return false;
                }
            }
        }
        return true;
    }
    
    void buildQuad(vector<vector<int>>& grid, Node* root, int x, int y, int n){
        if(checkvalue(grid, x, y, n)){
            root->isLeaf = true;
            root->val = grid[x][y];
        }
        else{
            root->isLeaf = false;
            root->val = 1;
            root->topLeft = new Node();
            buildQuad(grid, root->topLeft, x, y, n/2);
            root->topRight = new Node();
            buildQuad(grid, root->topRight, x, y + n/2, n/2);
            root->bottomLeft = new Node();
            buildQuad(grid, root->bottomLeft, x + n/2, y, n/2);
            root->bottomRight = new Node();
            buildQuad(grid, root->bottomRight, x + n/2, y + n/2, n/2);
        }
    }
    
    Node* construct(vector<vector<int>>& grid) {
        Node* root = new Node();
        int n = grid.size();
        buildQuad(grid, root, 0, 0, n);
        return root;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)