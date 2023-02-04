/* 1. Iterate from right
   2. Get first idx such that nums[idx]>nums[idx+1]
   3. Iterate from right and get first idx whose value is greater than idx 
      let's call it largeridx
   4. Swap nums[idx] to nums[largeridx]
   5. Reverse idx+1 onwards values
   6. Return answer */

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int len = nums.size();
        int idx = len-2;
        
        while(idx>=0 && nums[idx+1] <= nums[idx])
            idx--;
        
        if(idx>=0)
        {
            int largeridx = len-1;
            
            while(nums[largeridx] <= nums[idx])
                largeridx--;
            
            swap(nums[idx],nums[largeridx]);
        }
        reverse(nums.begin()+idx+1, nums.end());
    }
};
