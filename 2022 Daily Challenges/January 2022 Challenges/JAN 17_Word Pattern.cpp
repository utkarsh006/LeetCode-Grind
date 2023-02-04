/*
Problem:  Word Pattern

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example
        Example 1:

            Input: pattern = "abba", s = "dog cat cat dog"
            Output: true

        Example 2:

            Input: pattern = "abba", s = "dog cat cat fish"
            Output: false

        Example 3:

            Input: pattern = "aaaa", s = "dog cat cat dog"
            Output: false
*/

/*
Approach

1. Firstly we will create a vector words to store all the word of string s.
   Then we will create a hashmap to map the charaters of pattern string with the word which are present in vectors.

2. So adding word of string s in vector we'll run a for loop , if until s[i] doesn't get an empty space we will
   add the characters in temp string and when we will get space we will push temp in vector and will make temp again as empty.

3. Once word of string s are added in vector words, we'll check if the pattern size is equal to words size or not
   because if pattern="abba" and words= ["dog","cat"] then ofcourse there will not be same pattern hence return false.

4. Now create a set to store the words so that if repeating words like "cat" with different pattern[i] occurs then we'll return false .
   Ex: pattern="abba" and words= ["dog","dog","dog","dog"] it should return false.

5. We will create a hashmap to store the characters and their words.

6. If characters are already not present in map then we'll insert them in map along with their word and simultaneously
   we'll insert the word like "dog" in set also so maintain the uniqueness.

7. If the character is already present in map then we'll see if mp[pattern[i]] != words[i] (means the word with which it is mapped is same as the words[i])
   then its fine otherwise return false.

8. If our character doesn't exist in map then before pushing them in set we'll check
   if that words[i] is already there in set if it's not then fine otherwise return false (many characters have same words[i]).

*/

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        vector<string> words;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                words.push_back(temp);
                temp = "";
            }
            else
            {
                temp = temp + s[i];
            }
        }
        // we have done push here because after the last word there is no space in string s , that's why we will push this word after the for loop.
        words.push_back(temp);
        if (pattern.size() != words.size())
            return false;

        set<string> st;
        for (int i = 0; i < words.size(); i++)
        {
            if (mp.find(pattern[i]) != mp.end())
            {
                if (mp[pattern[i]] != words[i])
                    return false;
            }
            else
            {
                if (st.count(words[i]) > 0)
                {
                    return false;
                }
                mp[pattern[i]] = words[i];
                st.insert(words[i]);
            }
        }
        return true;
    }
};

/*
Time Complexity:O(N)
Space Complexity:O(N)
*/