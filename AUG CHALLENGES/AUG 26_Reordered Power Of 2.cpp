/*
Problem Statement:

You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Examples:
    Example 1:
        Input: n = 1
        Output: true
        
    Example 2:
        Input: n = 10
        Output: false

Approach: (Brute Force using sorting)

We can convert 'n' into string, sort it and compare it with every power of 2 which is also a string in sorted order.

1. Convert 'n' into a string and store it in 's'
2. Sort the string in ascending order
3. Iterate and compare with powers of 2 from 2^0 to 2^30, Since it's given that n < 10^9
4. Convert each powers of 2 into string ,sort it and store the result in string 'pow2'
5. If the sorted string 'pow2' is equal to 's' then return True, else move to next power of 2 and repeat the above steps.
6. If 'n' not found in all the 30 powers of 2 then return False

*/

class Solution 
{
public:
    bool reorderedPowerOf2(int n) 
    {
        string s = to_string(n);
        sort(begin(s), end(s));
        int pow = 1;
        for(int i = 0; i < 30; i++)
        {
            string pow2 = to_string(pow);
            sort(begin(pow2), end(pow2));
            if (s == pow2)
            {
                return true;  
            }
            pow <<= 1;
        }
        return false;
    }
};

/*
Complexity Analysis

Time Complexity: O(log n)
Space Complexity: O(1)
*/