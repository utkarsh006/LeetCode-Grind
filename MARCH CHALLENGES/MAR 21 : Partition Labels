class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector <int> endidx(26,0); // keep the track of last occurrence of every character
        vector <int> res;
        int start=0, end=0;
        
          for(int i=0;i<s.length();i++)
              endidx[s[i]-'a'] = i;
        
          for(int i = 0; i < s.length(); ++i)
          {
		  // get a character, we check, last index of that character
            end = max(end, endidx[s[i] - 'a']);
            
			// when current i == end then add it to result
                if( i == end)
                {
                  // all the characters of current partition included
                    res.push_back(i - start + 1);
				  // update the start pointer for fresh start
                     start = i + 1;
                }
          }
        
        return res;
    }
};
