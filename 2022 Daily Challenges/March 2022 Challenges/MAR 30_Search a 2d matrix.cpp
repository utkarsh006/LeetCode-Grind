/*
Problem :
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Approach:
1. According to the issue statement, the values of the last column in the ith row are higher than those of the first column in the (i+1)th row. 
Each row is also sorted.
This indicates that if we organize the components of each row in a linear fashion, we will get a sorted array.
Because of this, we can now run a binary search over it.
2. An array created from a n*m matrix matrix[x][y]: array [x * m+y]
3. A matrix can be created from an array (n * m):  a[x] : matrix[x / m][x % m]

Steps :
1. Apply the above algorithm to the matrix to operate it as an array.
2. Run a binary search on the matrix to find the desired element.

*/

class Solution
{ 
     public: bool searchMatrix(vector<vector<int>>& matrix, int target) 
          {
            int row = matrix.size();
            int col = matrix[0].size();
            int start=0;
            int end = (row*col)-1;
               while(start<=end)
               { 
                   int mid = start+(end-start)/2;
                   // a[x] : matrix[x / m][x % m] formulae
                   int element = matrix[mid/col][mid%col];
                   if(element == target)
                       return 1;
                   else if(element < target)
                       start=mid+1;
                   else
                       end=mid-1;
               }
           return 0;
          }
};

/*
Time Complexity: O(log(m*n)) = O(log(m) + log(n))
Space Complexity: O(1)
*/
