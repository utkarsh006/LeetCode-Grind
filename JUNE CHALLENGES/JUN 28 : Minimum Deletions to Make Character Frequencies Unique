
class Solution {
public:
    int minDeletions(string s)
    {
        vector<int> v(26);
         for(auto x: s)
         {
             v[x-'a']++;
         }
        sort(v.begin(),v.end(),greater<int>());
        
        int maxfreq = v[0]; int ans=0;
        
           for(auto x:v)  //traverse the frequencies
           {
               if(x>maxfreq)
               {
                   if(maxfreq>0) 
                       ans += (x-maxfreq);
                   else
                       ans += x;
               }
               maxfreq = min(maxfreq-1,x-1);
           }
        return ans;
        
    }
};
