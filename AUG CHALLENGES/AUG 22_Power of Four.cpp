/* Problem :
Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:

Input: n = 16
Output: true


Example 2:

Input: n = 5
Output: false


Example 3:

Input: n = 1
Output: true
*/


/* Approach :
How do we determine if a number is a power of four? Try to divide it by 4 and see if we still have 1 after numerous divisions.
This is a simple procedure, however the complexity will be O (log n). There is a better method.
We must look for 3 things in order to determine whether a number is a power of 4:

1. The value is positive.
2. Number is a power of two.
3. The power of this two is even power.

The first requirement is simple. The x&(x-1) method, which eliminates the final significant bit from a binary representation,
    can be used to solve the second requirement. For instance, 11010 & 11001 = 11000. If a number has just one significant bit,
    it is a power of two, hence after this operation, it must equal zero.

The final step can be challenging. Hopefully, by the time we get to this stage, we already know that the number is a power of 2,
    leaving us with only a limited number of options: 1, 10, 100, 1000,... How can we tell one half of them (odd powers) from from the other?
    Utilizing the binary mask m = 1010101010101010101010101 is the trick.
*/


class Solution
{
    public:
        bool isPowerOfFour(int n)
        {
            return num > 0 && !(num & (num - 1)) && (num & 0x55555555);
        }
};


/*
Time Complexity : O(1)
Space Complexity : O(1)
*/
