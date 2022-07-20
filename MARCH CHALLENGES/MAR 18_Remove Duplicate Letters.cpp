https://leetcode.com/problems/remove-duplicate-letters/discuss/890511/Remove-Duplicate-Letters-or-java-or-c%2B%2B-or-O(N)

class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        string res="";
        int lastPos[26] = {}; // the last position of the char
        bool added[26] = {};  // if the char is added to the result
        for (int i = 0; i < s.size(); i++)
        {
            lastPos[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (added[s[i] - 'a']) continue;
            while ( !res.empty() && res.back() > s[i] && lastPos[res.back() - 'a'] > i)
            {
                added[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            added[s[i] - 'a'] = true;
        }
        return res;
    }
};
