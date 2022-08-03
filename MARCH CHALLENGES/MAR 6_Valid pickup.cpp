/* Problem :
Given n orders, each order consist in pickup and delivery services. 
Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: n = 1, Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.


Example 2:

Input: n = 2, Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
*/

/* Approach :
1. Each order consists of 2 operations, they are pickup and delivery.
        1 order => 2 operations
        2 order => 4 operations
        .
        .
        n order => 2n operations
2. Number of ways, these 2n operations can be arranged is 2n!.
3. If there is just one order, with just one pickup (P1) and one delivery (D1), then
    There are two conceivable configurations: P1 D1 and D1 P1.
    Therefore, there is a 50% or 1/2 probability of scheduling one pickup and delivery in the proper order.
4. The sequence is invalid if there are N orders and any order's pickup or delivery is reversed.
    Therefore, in order to have a legitimate sequence of N orders, all N pairs of Pi Di must be in the right order, with each pair having a chance of 1/2. 
    Thus, this is how likely it is that N orders will be placed in a legitimate sequence ->
    1/2 * 1/2 * 1/2 * ..... 1/2(N times) = 1 / 2^N.

5. Thus, the ultimate answer is 2n!/2^n .      
*/

class Solution 
{
    public:
        int mod = 1e9+7;
        int countOrders(int n) 
        { 
             long places = 2*n;
             long seq = 1;

             for(int i=n;i>=1;i--)
             {
                 seq = (seq*(places*(places-1))/2) % mod;
                 places = places-2;
             }
         return (int)seq;
        }
};

/*
Time Complexity = O(n), where n is the number of orders
Space Complexity = O(1)
*/
