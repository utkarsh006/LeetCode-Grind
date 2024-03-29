/*
Problem: Remove Palindromic Subsequences

You are given a string s consisting only of letters 'a' and 'b'. In a single step you can remove one palindromic subsequence from s.

Return the minimum number of steps to make the given string empty.

A string is a subsequence of a given string if it is generated by deleting some characters of a given string without changing its order. 
Note that a subsequence does not necessarily need to be contiguous.

A string is called palindrome if is one that reads the same backward as well as forward.
*/

/*
Example:
        Example 1:

        Input: s = "ababa"
        Output: 1
        Explanation: s is already a palindrome, so its entirety can be removed in a single step.
        Example 2:

        Input: s = "abb"
        Output: 2
        Explanation: "abb" -> "bb" -> "".
        Remove palindromic subsequence "a" then "bb".
        Example 3:

        Input: s = "baabb"
        Output: 2
        Explanation: "baabb" -> "b" -> "".
        Remove palindromic subsequence "baab" then "b".

*/

/*
Approach

1. Edge Case: If string size is 0 then we can't have any palindrome so return 0.

2. Keep two pointers i=0 and j=size-1.

3. While i<j check if s[i] is equal to s[j] or not
        - If s[i]!=s[j] then we'll return 2 as answer because in the input we've only two characters 'a' and 'b'.
          So in 1st step we can remove all palindromic subsequence of 'a' and in step 2 we can remove all palindromic subsequence of 'b'.
        - if they are equal then move i forward and j backward.
        - we will return 1 as answer if our whole string is a palindrome.
*/

int removePalindromeSub(string s)
{
    if (s.size() == 0)
        return 0;

    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return 2;
        i++;
        j--;
    }
    return 1;
}

/*
Time Complexity:O(N)
Space Complexity:O(1)
*/