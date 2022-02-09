// LEETCODE 532 K diff pairs in array
class Solution 
{ public:   int findPairs(vector<int>& nums, int k)
            {  unordered_map<int,int> mp;
                 for(auto it:nums)
                       mp[it]++;
                    int ans = 0;
             
                    for(auto it:mp)
                    { int find = it.first + k;
                        if(mp.find(find) != mp.end())
                        { if(find == it.first && mp[find] > 1)
                                 ans++;
                          else if(find != it.first)
                                ans++;
                        }
                    }
                          return ans;
              }
};
