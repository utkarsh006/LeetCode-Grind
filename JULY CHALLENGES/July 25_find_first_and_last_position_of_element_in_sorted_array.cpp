class Solution {
public:
    
    //function to find the starting position of the target using binary search.
    int getPos1(vector<int>& nums, int low, int high, int& target){

        //loop runs only when low is lesser than high
        while(low <= high){
            int mid = low + (high - low) / 2;

            //since the array is sorted, it means required element must be present on the left side
            if(nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    
    
    //function to find last position of target using binary search
    int getPos2(vector<int>& nums, int low, int high, int& target){
        while(low <= high){
            int mid = low + (high - low) / 2;

          //since the array is sorted, it means required element must be present on the right side
            if(nums[mid] <= target)
                low = mid + 1;
            
            else
                high = mid - 1;
        }
        return high;
    }
    
    //main function to output
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0) 
            return {-1, -1};

        int low = 0, high = nums.size() - 1;

        vector<int> res;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
            {
                int pos1 = getPos1(nums, low, mid, target);
                int pos2 = getPos2(nums, mid, high, target);
                res.push_back(pos1);
                res.push_back(pos2);
                return res;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
        
    }
};

//Time Complexity: O(log n)
//Space Complexity: O(1)
