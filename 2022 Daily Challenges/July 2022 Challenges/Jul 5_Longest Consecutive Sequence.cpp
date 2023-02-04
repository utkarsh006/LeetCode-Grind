class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> sets(nums.begin(), nums.end());
        int ans = 0;
        
           for(auto i: nums)
           {
               if(sets.find(i) == sets.end()) continue;
               
               int prev = i-1, next = i+1;
               
               while(sets.find(prev) != sets.end())  prev--;
               while(sets.find(next) != sets.end())  next++;
               
               ans = max(ans, next-prev-1);
               sets.erase(i);
           }
        
        return ans;
    }
};
