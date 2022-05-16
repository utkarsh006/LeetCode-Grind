class Solution {
public:
    bool valid(int r, int c, vector<vector<int>>& grid, int m, int n)
    {
        if(r>=0 && c>=0 && r<=m && c<=n && grid[r][c]==0)
            return true;
        
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if(grid[0][0]==1) return -1;      //path is blocked
        
       // checking all 8 directions through 2D Vector
        vector<vector<int>> dir = 
        { {-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {1,1}, {1,-1}, {-1,1} };
        
        // we are inserting a pair of row and col into queue
        queue<pair<int,int>> q;
        
        q.push({0,0});   // enter the first row & col into the queue
        grid[0][0]=1;     //mark as visited
        int level = 0;
        
        int m = grid.size()-1;  int n = grid[0].size()-1;
        
              while(!q.empty())
              {
                  int level_size = q.size();
                  level++;
            
                    for(int i=0; i<level_size; i++)
                    {
                        pair<int,int> p = q.front();
                        q.pop(); 
                        
                        if(p.first==m && p.second==n)   return level;
                        
                       // check all other 8 directions  
                        for(int j=0; j<dir.size(); j++)
                        {
                            int r = p.first + dir[j][0];
                            int c = p.second + dir[j][1];
                            
                            if(valid(r,c,grid,m,n))
                            {
                                q.push({r,c});
                                grid[r][c]=1;
                            }
                        }
                    }
              }
        return -1;
    }
};
