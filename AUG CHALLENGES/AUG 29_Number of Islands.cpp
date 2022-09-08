/*
Problem: Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

*/

/*
Example:

        Example 1:
        Input: grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
        ]
        Output: 1

        Example 2:
        Input: grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
        ]
        Output: 3

*/

/*
Approach

1. Take 2 variable n and m for storing the size of grid, and a count =0 variable for counting the number of islands.

2. Now run two nested for loops first one from i=0->n and inside that other from j=0->m , 
   check the condition if grid[i][j]=='1' then only we'll go for recursion because islands are represented by '1'.

3. If grid[i][j]='0' that means there is no island so no need for traversing that part.

4. So if we will go inside if condition that means there must be an island so we'll increment the count and will go for recursion.

5. In recursive function we'll change the grid[i][j] as 0 because we've already traversed it so no means of doing it again & again.

6. Now we'll call recurisve function in all four directions(up,down,right,left) and that will cover all the islands attach to each other.

7. Base Case: if i and j reaches out of index we'll return or if grid[i][j] =0 then also we'll return.

8. Return the count.
*/

class Solution
{
public:
    void islands(int i, int j, vector<vector<char>> &grid, int &count)
    {
        int n = grid.size();
        int m = grid[0].size();
        // base cases when i & j reaches out of index
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        // when we reach again to grid[i][j]=0 then we'll return because it's not an island.
        if (grid[i][j] == '0')
            return;

        // if we've traversed that island we'll mark as 0 ,so we don't traverse it again
        grid[i][j] = '0';

        islands(i + 1, j, grid, count); // calling for down direction
        islands(i, j - 1, grid, count); // calling for left direction
        islands(i - 1, j, grid, count); // calling for up direction
        islands(i, j + 1, grid, count); // calling for right direction
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // islands are represnted by '1' so we'll only go inside if grid[i][j]=1
                if (grid[i][j] == '1')
                {
                    /*whenver we'll come inside this if condition that means there must be 1 island in all,
                     if the islands are connected to each other then they'll be considered as 1
                     */
                    count++;
                    islands(i, j, grid, count);
                }
            }
        }
        return count;
    }
};

/*
Time Complexity: O(M*N)
Space Complexity: O(M*N) recursive stack space
*/