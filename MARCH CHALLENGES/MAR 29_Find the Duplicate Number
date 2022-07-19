class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {   
        int n = nums.size();
        int start = 1, end=n-1, cnt;
        
        while(start<=end)
        {
            int mid = start + (end-start) / 2;
            cnt = 0;
            
            // cnt number less than equal to mid
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                start = mid + 1;
            else
            // binary search on right
                end = mid - 1;
            
        }
        return start;
    }
};
