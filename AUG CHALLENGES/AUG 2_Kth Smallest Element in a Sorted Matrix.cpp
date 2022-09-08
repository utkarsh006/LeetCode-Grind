/* Problem :
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2).
*/

/* Approach 1:(Using Binary Search)
If the matrix is sorted, binary search may often be used to determine the solution.
Set the lower and upper limit values first.
We know that the first row and column have the smallest value, and the last row and column contain the highest value.
Now, binary search logic is used in the kth smallest function.
After determining the midpoint, we manipulate the lower and upper bounds to determine the solution.
In the Count function, we essentially count the number of values in the matrix that are less than or equal to our target (MID value),
and then adjust our lower and upper bounds accordingly.
*/

/* Steps :
1. If the values [from Row 0 to current_row] are less than or equal to the target,
    we may assume that the values [from curr_row, curr_col] will likewise be less than the target (because column is sorted).
    As a result, we may use the formula (curr_row+1) to advance to the following column and count the components that are fewer than or equal to the goal.

2. If the value is more than the current row and column, we can advance upwards using the notation (curr_row—) in the hopes of discovering a value that is less than or equal to the target.
    Additionally, because the row is sorted, we won't miss any values that are less than or equal to the objective as we move higher.

3. After we get the count, we may determine whether it is more than K, at which point we can narrow the range.

4. If not, raise it since, in order to achieve the Kth lowest element, you must have (K-1) elements.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {

        int n=mat.size(),lb=mat[0][0],ub=mat[n-1][n-1];

        while(lb<ub)
        {
            int mid=lb-(lb-ub)/2;
            int res=count(mat,n,mid);
            if(res>=k)
                ub=mid;
            else
                lb=mid+1;
        }
        return ub;
    }
    int count(vector<vector<int>> &mat, int n,int target)
    {
        int curr_row=n-1,curr_col=0,count=0;
        while(curr_row>=0 && curr_col<n)
        {
            if(mat[curr_row][curr_col]<=target)
            {
                count+=(curr_row+1);
                curr_col++;
            }
            else
                curr_row--;
        }
        return count;
    }
};

/*
Time Complexity:- O(N logN)
Space Complexity:- O(1)
*/
