class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int &area, int &maxIsland)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        //corner cases for moving in the 4 directions left, right, top, bottom
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j] ==0) return;
        
        //changing the value of island to 0 after its been added so that we don't count it again later
        grid[i][j]=0;
        //couting the islands
        area++;  

        dfs(grid,i-1,j,area,maxIsland);    //  moving to the top
        dfs(grid,i+1,j,area,maxIsland);    //  moving to the down 
        dfs(grid,i,j-1,area,maxIsland);     // moving to the left
        dfs(grid,i,j+1,area,maxIsland);    //  moving to the right
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int maxIsland=0;
        int n=grid.size();
        int m=grid[0].size();

        // moving in every point of grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //going only for the cells which has value 1 so as to minimize our computations
                if(grid[i][j]==1)  
                {
                    //making the value of area as 0 so that everytime when we come in for loop it starts the couting island from fresh
                    area=0;
                    dfs(grid,i,j,area,maxIsland);
                    // calculating the count of number of maxIsland
                    maxIsland=max(area,maxIsland);
                }
            }
        }
        return maxIsland;
    }
};

//  here N=number of rows & M= number of columns
#Time_Complexity: O(N*M)  //we may visit every cell once
#Space_Complexity: O(N*M) //recursion stack space