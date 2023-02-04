/*
Problem Statement:

Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
- Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
- Each vowel 'a' may only be followed by an 'e'.
- Each vowel 'e' may only be followed by an 'a' or an 'i'.
- Each vowel 'i' may not be followed by another 'i'.
- Each vowel 'o' may only be followed by an 'i' or a 'u'.
- Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Examples:
    Example 1:
        Input: n = 1
        Output: 5
        Explanation: All possible strings are: "a", "e", "i" , "o" and "u".

    Example 2:
        Input: n = 2
        Output: 10
        Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".

Approach:

1. Store the words ending with vowels in variables 'a','e','i','o','u' respectively.
2. Since there are five possible single letter words at start, initailize all variables to one.
3. For n-1 loops add the no of words ending with vowels to respective variables.
4. Add word count to variables according to the constraints given in every loop.
5. For Example words ending with letter 'a' are sum of the words ended with 'e','i' and 'u' in previous loops.
6. Make sure to modulo variables in each loop, to avoid integer overflow.
*/

class Solution 
{
public:
    int countVowelPermutation(int n) 
    {
        long long int a=1,e=1,i=1,o=1,u=1; // Initialize variables to 1
        for(int j=1;j<n;j++)
        {
            long long int t1=a,t2=e,t3=i,t4=o,t5=u; // Storing values temporarily to avoid Redundancy
            a=(t2+t3+t5)%1000000007;
            e=(t1+t3)%1000000007;
            i=(t2+t4)%1000000007;
            o=t3%1000000007;
            u=(t3+t4)%1000000007;
        }
        return (a+e+i+o+u)%1000000007;  // Return Total number of possible strings 
    }
};


/*
Time Complexity: O(n)
Space Complexity: O(1)
*/