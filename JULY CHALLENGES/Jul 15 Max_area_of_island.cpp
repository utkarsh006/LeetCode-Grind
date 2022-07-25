class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int &area, int &maxIsland)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j] ==0) return;
        
        grid[i][j]=0;
        area++;
        dfs(grid,i-1,j,area,maxIsland);
        dfs(grid,i+1,j,area,maxIsland);
        dfs(grid,i,j-1,area,maxIsland);
        dfs(grid,i,j+1,area,maxIsland);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int maxIsland=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    area=0;
                    dfs(grid,i,j,area,maxIsland);
                    maxIsland=max(area,maxIsland);
                }
            }
        }
        return maxIsland;
    }
};