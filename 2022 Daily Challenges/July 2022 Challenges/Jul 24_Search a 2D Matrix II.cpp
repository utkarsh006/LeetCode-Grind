/* Problem
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

/* Approach
1. Begin iterating the matrix at matrix[0][size of column -1], which is the top right corner of the matrix.
2. Return true if matrix[i][j]==target.
3. Move left (reduce the column), which is --j, if the target is less than matrix[i][j].
4. Move downward (raise the row) if the target is greater than matrix[i][j], which is ++i.
5. Return false after ending the above loop, if the target element cannot be located.
*/

// CODE IMPLEMENTATION
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        // start from the [first row, last column] element
        int i=0;
        int j=m-1;
        while(i<n && j>=0)
            {
            // target found
            if(matrix[i][j]==target)
                return true;
            //target is smaller, go leftwards
            else if(matrix[i][j]>target)
                --j;
            // target is larger, go downwards
            else
                ++i;
        }
        // target not found
        return false;
    }
};
/*
Considering, m = length of column and n = length of row.
TIME COMPLEXITY: O(m+n)
SPACE COMPLEXITY: O(1)
*/
