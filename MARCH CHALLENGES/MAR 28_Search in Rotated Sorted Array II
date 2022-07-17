class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int mid = start+(end-start)/2;
        
            while(start<=end)
            {
                if(nums[mid]==target)
                    return true;
                
                else if((nums[start] == nums[mid]) && (nums[end] == nums[mid]))
                {
                   start++;
                   end--;
                }
                // left side is sorted
                else if(nums[start] <= nums[mid])
                {  // figure out element lies on left half or not
                    if(target>=nums[start] && target<=nums[mid])
                        end = mid-1;
                    else
                    start = mid+1;
                }
                
                else
                {  // figure out element lies on right half or not
                    if(target>=nums[mid] && target<=nums[end])
                        start = mid+1;
                    else
                        end = mid-1;
                }
                mid = start+(end-start)/2;  // update mid
            }
        return false;
    }
};
    
