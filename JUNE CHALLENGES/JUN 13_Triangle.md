## Problem Statement 

Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, 
you may move to either index i or index i + 1 on the next row.

## Example

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]

Output: 11

Explanation: The triangle looks like:

```

  2
   
  3 4
  
  6 5 7
 
  4 1 8 3


```

The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.


## Constraints:

- 1 <= triangle.length <= 200

- triangle[0].length == 1

- triangle[i].length == triangle[i - 1].length + 1

- -104 <= triangle[i][j] <= 104

## Approach

- In this question we are supposed to find the minimum path sum from top to buttom provided that we can either move to index i or index i + 1 on the next row.

- So if we are present on the cell say triangle[currRow][currCol] then we are having two options :- 

      i.move down i.e we'll reach triangle[currRow + 1][currCol].
      
      ii.move diagoanally down i.e. we'll reach triangle[currRow + 1][currCol + 1].
      
- We'll explore the above two possibilities and will return the minimum of them,until we reach the last row.


## Code

```cpp

class Solution {
public:
    
    //function to find min path sum
    int minPathSum(int currRow,int currCol,int targetRow,vector<vector<int>> &triangle,
                  vector<vector<int>>&memo)
    {
        //if we have reached the last row
        //then return the value present in that cell
        if(currRow == targetRow)
            return triangle[currRow][currCol];
        
        //if we are having the answer of the current cell in memo
        //then simply return it
        if(memo[currRow][currCol] != -1)
            return memo[currRow][currCol];
        
        //exploring the two possibilities
        int down = triangle[currRow][currCol] + minPathSum(currRow+1,currCol,targetRow,triangle,memo);
        int diagonal = triangle[currRow][currCol] + minPathSum(currRow+1,currCol+1,targetRow,triangle,memo);
        
        //storing answer of current cell in memo for future reference
        memo[currRow][currCol] = min(down,diagonal);
        return memo[currRow][currCol];
    }
    
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int len = triangle.size()-1;
        
        vector<vector<int>>memo(len,vector<int>(len,-1));
        
        int ans = minPathSum(0,0,len,triangle,memo);
        
        return ans;
    }
};


```


## Time Complexity = O(exponential)
## Space Complexity = O(N)

