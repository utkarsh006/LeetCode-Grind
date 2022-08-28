/* Problem :
Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3^x.
*/


/* Approach 1:(Modulo)
Due to the prime nature of 3, only powers of 3 that are equal or smaller can be divided by powers of 3.
We can take use of this by conducting a modulo n operation on the biggest power of three we can within our limitations (3^19).
In the event that the outcome is 0, n is a power of 3.
*/

class Solution
{
    public:
        bool isPowerOfThree(int n)
        {
            return n > 0 && 1162261467 % n == 0;
        }
};



/* Approach 2:(Logarithmic)
To obtain the answer, we can make use of logarithms' inherent mathematical features.
3^x = n if n is a power of three. If n is a power of three, this can be phrased as log3 n = x,
where x will be an integer.

Due to the fact that most computer languages lack native support for log3 calculations,
we can benefit from another characteristic of logarithms: log3 n can be represented as log n / log 3.
While n is restricted to an integer, this will result in a small amount of floating point inaccuracy,
but any value that is within a narrow margin (1e-10) will be correct.
*/

class Solution
{
    public:
        bool isPowerOfThree(int n)
        {
            double a = log(n) / log(3);
            return abs(a - round(a)) < 1e-10;
        }
};



/*
Time Complexity : O(1)
Space Complexity : O(1)
*/
