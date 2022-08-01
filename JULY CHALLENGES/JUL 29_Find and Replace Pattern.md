## Problem Statement

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

## Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"

Output: ["mee","aqq"]

Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 

"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

## Example 2:

Input: words = ["a","b","c"], pattern = "a"

Output: ["a","b","c"]

## Intuition

1. Store the indices of all the characters of pattern in an unordered map(say mp).

2. Now iterate over words to get the currWord.

3. Store the indices of all the characters of currWord in a different unordered map(say mw).

4. Now iterate upto their size and check if any of the charaters present at the i-th index of pattern and currWord are occuring in different indices then set flag as false and break , and we won't add it to ans.

5. Otherwise add it to ans.


## Code


```cpp


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string>ans;
        
        unordered_map<char,vector<int>>mp;//character : [their corresponding indices]
        //storing characters of pattern as key and their corresponding indices as value
        for(int i=0; i<pattern.size(); i++)
            mp[pattern[i]].push_back(i);
        
        for(auto currWord : words)
        {
            unordered_map<char,vector<int>>mw;//character : [their corresponding indices]
          //storing characters of currWord as key and their corresponding indices as value
            for(int i=0; i<currWord.size(); i++)
                mw[currWord[i]].push_back(i);
            
            bool flag = true;
            
            for(int i=0; i<mp.size(); i++)
            {
                if(mp[pattern[i]] != mw[currWord[i]])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag == true)
                ans.push_back(currWord);
        }
        
        return ans;
    }
};


```


#### Time Complexity = O(N * M), where N is the length of words and M is the length of pattern 

#### Space Complexity = O(N), since we are using unordered maps.


