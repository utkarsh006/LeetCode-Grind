/*
Problem: Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

/*
Examples:

    Example 1:
        Input: candidates = [2,3,6,7], target = 7
        Output: [[2,2,3],[7]]
        Explanation:
        2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
        7 is a candidate, and 7 = 7.
        These are the only two combinations.

    Example 2:
        Input: candidates = [2,3,5], target = 8
        Output: [[2,2,2,2],[2,3,3],[3,5]]

    Example 3:
        Input: candidates = [2], target = 1
        Output: []

*/

/*
Approach

1. Here we have to find out every unique combination sum possible which will be equal to target.

2. We'll check for every element of array , if that element in less than target then we'll move forward with
    considering the combination,otherwise will backtrack.

3. Instead of adding  sum in different variable we have subtracted candidates[i] from target so our target
   will keep on decreasing with every valid combination.

4. If candidates[i] is greater than target then we will simply backtrack and will call function for
   next value, because adding further will not give us any combination.

5. If candidates[i] is equal to target then we will store the result as our combination & will
   not move forward because it will only exceed the sum.

6.If candidates[i] is less than target then we will add the element in the vector and will again
  call for the same index and will subtract the element from target, while backtracking we will pop the element 
  from the vector and will call for next index.

7. Base case : If our target becomes 0 that means we got a combination and we will add our
    vector in the final vector as answer and will return.

8. Even if our index reached equal to the size of vector then also we will check if our target
    is 0 then add vector in ans vector otherwise if target is not 0 then simply return.

*/

class Solution
{
public:
    void combination(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &v, int i)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        if (i == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(v);
            }
            else
                return;
        }
        if (candidates[i] <= target)
        {
            v.push_back(candidates[i]);
            combination(candidates, target - candidates[i], ans, v, i);
            v.pop_back();
        }

        combination(candidates, target, ans, v, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        combination(candidates, target, ans, v, 0);
        return ans;
    }
};

/*
Time Complexity: O((2^target)*k) {here suppose target is 10 then we can take an element as 10 times which is equal to target so 2^target and  k is average length which it will take for every recursion call}

Space Complexity:O(k* no. of combinations)
*/