class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    { 
        int n = nums.size();
        int l = 0, r = n-1;
        
        while(l<r)
        {
            if(nums[l]%2==0)
            {
                l++;
            }
            else
            {
                swap(nums[l],nums[r]);
                r--;
            }
        }
        return nums;
    }
};
