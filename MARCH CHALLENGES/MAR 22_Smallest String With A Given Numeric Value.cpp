/* Problem : 
Smallest String With A Given Numeric Value

The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.
The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.
You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.
Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.
*/

/* Approach :
1. To make the smallest possible lexiographic string, start a string s with n 'a'.
2. Count of 'a = 1', thus if I have n of 'a', the sum is also 'n'.
3. Reduce k's value by n (k=k-n);
4. Begin traversing the string from the end because if we append any character from the beginning, we may not acquire the lowest feasible lexiographic order.
5. Stop the traverse if 'k' becomes '0,' because it would be our response.
6. Otherwise, if k = 25, it means that to get the sum, simply replace the ith character with 'a'+k. And increment k by k=0.
7. If k is greater than 25, iterate more and replace the ith character with ('a'+25) before proceeding. Also, increase k by k-25.
*/

class Solution 
{
public:
    string getSmallestString(int n, int k)
    {
        // initialising string of length n with all 'a';
        string str(n,'a');
        // as all 'a' are 1 and therefore we have subtract there sum;
        k -= n;
        while( k > 0)
        {
            // turning rightmost digit , 'a' into 'z' ('a' + 25, or 'a' + k)
            // while k is positive.
            str[--n] += min(25,k);
            k -= min(25,k);
        }
        return str;
    }
};

/*
Time Complexity : O(N)
Space Complexity : O(1)
*/
