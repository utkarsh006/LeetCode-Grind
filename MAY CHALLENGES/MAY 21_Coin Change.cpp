/* Problem :
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.


Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
*/

/* Approach :
Here, we must determine the bare minimum of coins needed for the specified sum.
Due to its optimum substructure property, which allows for the discovery of the complete problem's solution
(i.e., the minimum number of coins for the total amount) through the optimal solution of a subproblem,
this problem can be modeled as a DP problem (min coins for 1, 2, 3..., amount).

1. We can select any number of free coins of any type for each value of amount from 1 to amount.
2. We are aware that the minimum amount of coins needed is zero (dp[0] = 0).
3. After that, we try to grab each coin and finally assign the minimum amount of coins to dp[1].
4. Up until the specified amount, this process is repeated for all quantities.
5. Finally, the required response will be dp[amount], which stands for the bare minimum of coins needed to create the specified amount.
*/

class Solution
{
public:
    int coinChange(vector<int>& coins, int n)
    {
        // Initializing the DynamicProg vector
        vector<int> DynamicProg(n+1, 1e9);
        DynamicProg[0] = 0;
        // take each amount and try each coin for that amount to find minimum coins required for that amount.
        for(int currAmount = 1 ; currAmount<=n ; currAmount++)
            {
            for(int j = 0 ; j<coins.size(); j++)
            {
                // only update DynamicProg[currAmount] if coin value is not greater than that current amount.
                if(currAmount>=coins[j])
                    DynamicProg[i] = min( DynamicProg[currAmount], DynamicProg[currAmount-coins[j]]);
            }
            DynamicProg[currAmount]++;
        }
        if(DynamicProg[n]>=1e9)return -1; //no possibilities of finding amount
        else return DynamicProg[n];
    }
};

/*
Time Complexity : O(N*W), Space Complexity : O(W)
where N is the number of coins given and
W is the total amount for which minimum coins are to be found.
*/
