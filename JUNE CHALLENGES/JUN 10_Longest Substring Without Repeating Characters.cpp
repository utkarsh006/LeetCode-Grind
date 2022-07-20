int lengthOfLongestSubstring(string s) 
    {
        vector<int> v(127,-1);
        int pos = -1, maxlen = 0;
        
           for(int i=0; i<s.size(); i++)
           {
               int ch = s[i];
               pos = max(pos, v[ch]);
               maxlen = max(maxlen, i-pos);
               v[ch]=i;
           }
        return maxlen;
    }
