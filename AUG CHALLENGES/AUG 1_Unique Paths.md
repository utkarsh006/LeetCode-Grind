
# [Unique Paths](https://leetcode.com/problems/unique-paths/)

- [Problem Statement](#problem-statement)

- [Examples](#examples)

- [Explanation](#explanation)

- [Code](#code)

- [Time Complexity and Space Complexity](#time-complexity-and-space-complexity)



### Problem Statement

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.


### Examples


##### Example 1:

![image](https://user-images.githubusercontent.com/75883328/161976152-6f2972ee-4561-4ffe-ac27-d27bd9ebe82b.png)


Input: m = 3, n = 7

Output: 28



##### Example 2:

Input: m = 3, n = 2

Output: 3

Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:

1. Right -> Down -> Down

2. Down -> Down -> Right

3. Down -> Right -> Down


### Explanation

- we have to return the number of possible unique paths that the robot can take to reach the bottom-right corner (i.e., grid[m - 1][n - 1]) from top-left corner (i.e., grid[0][0])

- So from any cell of the grid we are having 2 options :-  1.either move down or 2. move right at any point in time.

- if we'll move down we'll reach grid[i+1][j] and on moving right we'll reach gird[i][j+1].

- if we'll reach grid[m-1][n-1] then. return 1 because its a valid path.

- if at any point i<0 or j<0 then, return 0 because its an invalid path.

This recursive code will give us a TLE.So, we need to optimize this.

We'll optimize this using DP ,because we have overlapping sub-problems.

- So we can store the values in a vector and will use those values from the vector only instead of making recursive calls for it.


 ## Code 
 
 ```cpp

int totalPaths(int currentRow,int currentCol,int targetRow,int targetCol,vector<vector<int>>&v)
{
    //base conditions
    if(currentRow==targetRow && currentCol==targetCol) return 1;//valid path
    if(currentRow<0 || currentCol<0 ||currentRow>targetRow ||currentCol>targetCol) return 0;//invalid path
        
    //if value is already present in the vector v ,then extract from it, no need to make recursive calls for it 
    if(v[currentRow][currentCol]!=-1) return v[currentRow][currentCol];
        
    //exploring the two possibilities :-1.right movement 2.downward movement
    int right = totalPaths(currentRow,currentCol+1,targetRow,targetCol,v); //when the robot moves right
    int down = totalPaths(currentRow+1,currentCol,targetRow,targetCol,v); //when the robot moves down
        
    //storing the answer for the current coordinate in v,so that we can use it in future
    v[currentRow][currentCol] = (right+down); 
    return v[currentRow][currentCol];
     
}
 int uniquePaths(int m, int n) 
{
    vector<vector<int>>v(m,vector<int>(n,-1));
    return totalPaths(0,0,m-1,n-1,v);
}


```
 
         
### Time Complexity and Space Complexity

#### Time Complexity = O(m * n)

#### Space Complexity = O(m * n)
