class Solution {
public:
    int path(int i,int j,int n,int m,int &c,int cnt,vector<vector<int>> &grid)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==-1 or grid[i][j]==3)
            return 0;
        
        // ending square
        if(grid[i][j]==2)
        {
            //if all empty cells visited then returning 1 else 0
            if(cnt-1 == c) return 1;
            return 0;
        }
        
        grid[i][j]=3;                  // mark as visited
        
        // all possible paths
        int up = path(i-1,j,n,m,c,cnt+1,grid);
        int down = path(i+1,j,n,m,c,cnt+1,grid);
        int left = path(i,j-1,n,m,c,cnt+1,grid);
        int right = path(i,j+1,n,m,c,cnt+1,grid);
    
        grid[i][j]=0;                          // mark as unvisited
        
        return up+down+left+right;   // total count of reaching ending square
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int start,end;
        int c=0;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                // if it is starting square
                if(grid[i][j]==1)
                {
                    start=i;
                    end=j;
                }
                
                // count of empty cells
                if(grid[i][j]==0)
                {
                    c++;
                }
            }
        }
        return path(start,end,rows,cols,c,0,grid);
    }
};
