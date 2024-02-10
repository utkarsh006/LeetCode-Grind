class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // initialise cnt vector of size nums with 0
        vector<int> cnt(nums.size(),0);
        int ind =  0;

        // store the cnt of each value in the cnt vector
        for(int i = 0; i<nums.size(); i++)
        {
            cnt[nums[i]]++;
        }

        for(int i = 0; i<cnt.size(); i++)
        {
            // if cnt[i] > 1
            // this means that element occur more than once in nums
            // we have to return i
            if(cnt[i] > 1)
            {
                ind  = i;
                break;
            }
        }

        return ind;
    }
};

/*
Time complexity: O(N)
Space complexity: O(N)
*/
