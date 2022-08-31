/* Problem :
You are given an n x n 2D matrix representing an image,
rotate the image by 90 degrees (clockwise).
Rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.
*/


/* Rotation:
    First row will be last column
    Second row will be second-to-last column
    ...
    Last row will be first column
*/


/* Approach:(For clockwise roation)
    Do a transpose of the matrix first
    Reverse each row of the matrix
for example :
    1 2 3       7 8 9       7 4 1
    4 5 6   ->  4 5 6   ->  8 5 2
    7 8 9       1 2 3       9 6 3
*/


class Solution
{
    public:
        void rotate(vector<vector<int>>& matrix)
        {
            reverse(matrix.begin(), matrix.end());
            for (int i = 0; i < matrix.size(); ++i)
            {
                for (int j = i + 1; j < matrix[i].size(); ++j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }
};

/*
Time Complexity : 0(N)
Space Complexity : 0(1)
*/
