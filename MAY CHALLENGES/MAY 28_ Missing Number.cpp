class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = 0;
        int res = nums.size();
        
          for(auto i: nums)
          {
              res = res ^ i;
              res = res ^ n;
              n++;
          }
        return res;
    }
};
