class Solution {
    vector<vector<int>> dirs = { 
         {-1,0},{0,-1},{0,1},{1, 0}
    };
    bool isValid(vector<vector<int>>& heights, int mx)
    {
        queue<pair<int,int>> q;
        int ROWS = heights.size();
        int COLS = heights[0].size();
        
        vector<vector<bool>> seen(ROWS, vector<bool>(COLS, false));
        q.push({0,0});
        seen[0][0] = true;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;
            if(r == ROWS - 1 && c == COLS - 1) return true;
            
            for(auto& dir : dirs) 
            {
                int dr = dir[0] + r;
                int dc = dir[1] + c;
                if(dr < 0 || dr >= ROWS) continue;
                if(dc < 0 || dc >= COLS) continue;
                if(seen[dr][dc]) continue;
                if(abs(heights[r][c] - heights[dr][dc]) > mx) continue;
                seen[dr][dc] = true;
                q.push({dr, dc});
            }
        }
        
        return false;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int L = 0;
        int R = INT_MAX;
        int best = INT_MAX;
        while(L <= R) 
        {
            int M = L + (R-L) / 2;
            
            if(isValid(heights, M))
            {
                R = M - 1;
                best = min(best, M);
            } 
            else 
                L = M + 1;
        }
        
        return best;
    }
};
