Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.


class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        if(s.size() < k) return false;
        unordered_set<string> set;
          
           for(int i=0; i<=s.size()-k; i++)
           {
               set.insert( s.substr(i,k) );
           }
        
        return (set.size() == pow(2,k));
    }
};
