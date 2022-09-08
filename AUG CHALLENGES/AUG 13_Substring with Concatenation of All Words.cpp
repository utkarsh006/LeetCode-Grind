/*
Problem Statement:

You are given a string s and an array of strings words. All the strings of words are of the same length.

- A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
- For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. 
- "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.

Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Example:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]

Explanation: 
    - Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
    - The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
    - The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
    - The output order does not matter. Returning [9,0] is fine too.

Approach : 

Using Hashing & Sliding Window Technique to solve the above problem.

1. Declare a map 'M' which stores all words count
2. Select a window of size 'wordsWindow' (total number of characters produced if all the words are concatenated).
3. Check if that window is possible to build using our map 'M'.
4. If True, add the starting index to our result vector 'ans'.
5. Increasing the window by 1 & check until we are able to select wordsWindow size window.
*/

class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {    
        unordered_map<string, int> M, temp;
        vector<int> ans;
        int N = words.size();
        int L = words[0].size();
        int wordsWindow = N*L;
        // Store all the frequencies of all strings in the array words[]
        for(auto &it : words) 
        {
            M[it]++;
        }
        int size = s.length();
        
        // Loop till possible number of starting index of the valid indices
        for(int i = 0; i < size - wordsWindow + 1; i++) 
        {    
            // Iterate the current window of length N*L over the range i to (i + N*L)
            // Extract the substring of length L and store it's frequency
            for(int j = i; j < i + wordsWindow; j+= L) 
            {
                string ans = s.substr(j, L);
                if(M.find(ans)!= M.end()) // string exists hance check for next word else this window is usless
                    temp[ans]++;
                else
                    break;
            }
            
            if(temp==M) //given at max of words are 36. hence it takes max 36 iterations
                ans.push_back(i);
            
            // Clear the temp for another window
            temp.clear();
        }
        
        // Return the resultant vector of indices
        return ans;
    }
};
/*
Complexity Analysis

Given 'n' as the length of s, 'a' as the length of words, and 'b' as the length of each word.

Time Complexity: O(a + n*b)
Space Complexity: O(a + b)
*/