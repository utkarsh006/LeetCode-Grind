
/*
intuition : Returning false if the length of the two strings are different ,ELSE storing the characters & their corresponding frequency  of both the strings 
in two different unordered maps.Returning false if the frequency of any element of the maps are different else returning true.

1. TC=O(n)
2. SC=O(n)
*/



class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int>ms;
        unordered_map<char,int>mt;
        
        for(auto i:s)
            ms[i]++;
        
        for(auto i:t)
            mt[i]++;
        
        if(ms.size()!=mt.size())
            return false;
        
        for(int i = 0;i<t.size();i++)
        {
            if(mt[t[i]] != ms[t[i]])
                return false;
        }
        return true;
    }
};
