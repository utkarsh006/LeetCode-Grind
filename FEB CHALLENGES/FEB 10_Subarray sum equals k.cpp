// LEETCODE 560 : Subarray sum equals k
class Solution 
{ public: int subarraySum(vector<int>& nums, int k)
          { int n=nums.size();
            int count=0;
            unordered_map<int, int> prevSum;
            int sum=0;
        
                   for(int i=0;i<n;i++)
                   { sum+=nums[i];
            
                           if(sum==k)
                              count++;
            
                       if(prevSum.find(sum-k) != prevSum.end())
                             count+=prevSum[sum-k];
            
                       prevSum[sum]++;
                  }
        
                 return count;
          }
};
