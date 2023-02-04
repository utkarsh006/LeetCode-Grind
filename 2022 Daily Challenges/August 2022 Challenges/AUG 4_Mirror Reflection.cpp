/* Problem :
There is a special square room with mirrors on each of the four walls.
Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.
The square room has walls of length p and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.
Given the two integers p and q, return the number of the receptor that the ray meets first.
The test cases are guaranteed so that the ray will meet a receptor eventually.

Example 1:

Input: p = 2, q = 1, Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.


Example 2:

Input: p = 3, q = 1, Output: 1

*/

/* Approach :
The left and right walls are alternately struck by the light.
The impact point's y coordinate will be q, 2q, 3q if we disregard the ceiling.
Finding the least common multiplier(lcm) of p and q, which determines where the ray will ultimately be received, is now crucial.
Since the ray is guaranteed to be received if the final y is an even multiple of p (lcm / p % 2 == 0), the receptor 0 will be hit.
If not, we check to see if receptor 2 received an even number of hits (lcm / q % 2 == 0).
For example, if we take the four corners to constitute a 2-row-2-column grid,
the row number is lcm / p % 2 (going bottom-up),
and the column number is 1 - lcm / q % 2. (going right-left).
The [[2,1],[1,0]] grid that results from adding them all up serves admirably as the receptor id.
Since lcm is defined as p * q / gcd,
we arrive at lcm / p % 2 + 1 - lcm / q % 2 = p * q / gcd / p % 2 + 1 - p * q / gcd / q % 2 = 1 + q / gcd % 2 - p / gcd % 2.
*/

class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        return 1 + q / gcd(p, q) % 2 - p / gcd(p, q) % 2;
    }
};

int gcd(int p, int q)
{
    return q ? gcd(q, p % q) : p;
}

/*
Time Complexity: O(log(q)), for the GCD computation
Space Complexity: O(1)
*/
