/** Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
  
  Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/



// C++ Solution

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0, r=0;   // left and right pointer
        int ansLen=0;     // final length of the string
       int maxCount=0;     // maximum occurence of current element
        unordered_map<char,int>mp;    // hashmap for storing occurence  of element
        while(r<n ){
            mp[s[r]]++;
         int windowLen=r-l+1;
            maxCount=max(maxCount, mp[s[r]]);
            if(windowLen-maxCount<=k){
                 ansLen=max(ansLen,(r-l+1));
               r++;
                cout<<"r"<<r<<' ';
                // mp[s[l]]--;
                // l++;
                
                
            }
            else{
                mp[s[l]]--;
                l++;
                r++;
                cout<<"l"<<l<<' ';
            }
            // ansLen=max(ansLen,(r-l+1));
            // r++;
            //cout<<"r"<<r;
        }
        return ansLen;
        
    }
};
