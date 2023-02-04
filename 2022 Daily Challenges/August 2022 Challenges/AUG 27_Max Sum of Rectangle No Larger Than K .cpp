/*
Problem : Max Sum of Rectangle No Larger Than K
Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.
*/

/*
Example:
        Example 1:
        Input: matrix = [[1,0,1],[0,-2,3]], k = 2
        Output: 2
        Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

        Example 2:
        Input: matrix = [[2,2,-1]], k = 3
        Output: 3
*/

/*
Approach:

1. We will create two pointers left and right and will iterate both of them till number of col, we chose col instead of rows because 
   it's mentioned in the ques we can have more number of rows than cols so eventually our complexity will increase if we use row thats why we've used cols.

2. We will keep a vector sum with the size as number of rows to keep the sum of cols between  rows

3. Now inside for loop of right pointer we will run another for loop from i=0->row and 
   there we'll calculate the cumulative sum of columns between rows and will keep storing that in sum vector.

4. Once that's done for particular iteration so when we'll come out of for loop of i, we'll create a set to store the prefix sum of the array.

5. Create a variable tot_sum to store the cumulative sum

6. Now run another for loop till size of vector sum and first store the sum of vector in tot_sum and find the lower bound of tot_sum-k from set.

7. If that's present in set then we'll find maximum and update our ans.

8. Atlast we'll insert every tot_sum in the set.

*/

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int row = matrix.size();    //number of rows
        int col = matrix[0].size(); //number of columns
        int ans = INT_MIN;

        for (int left = 0; left < col; left++)
        {
            // will make a vector to store the sum and it's size will be equal to the number of rows
            vector<int> sum(row);
            for (int right = left; right < col; right++)
            {
                for (int i = 0; i < row; i++)
                {
                    // taking cumulative sum of columns between the two rows
                    sum[i] += matrix[i][right];
                }
                // will create a set to store the prefix sum of array
                set<int> st;
                st.insert(0);
                // tot_sum will store cumulative sum
                int tot_sum = 0;
                // size is the size of the sum vector 
                int size = sum.size();
                for (int j = 0; j < size; j++)
                {
                    // calculate the cumulative sum of vector sum
                    tot_sum += sum[j];
                    // finding the lower bound in the set of cumulative sum == tot_sum - k
                    auto it = st.lower_bound(tot_sum - k);
                    // if it's present then we will update our ans
                    if (it != st.end())
                    {
                        ans = max(ans, tot_sum - *it);
                    }
                    // insert every prefix sum into the set
                    st.insert(tot_sum);
                }
            }
        }
        return ans;
    }
};

/*
Time  Complexity: O(col * col * row * log(row))
Space Complexity:O(row)

*/