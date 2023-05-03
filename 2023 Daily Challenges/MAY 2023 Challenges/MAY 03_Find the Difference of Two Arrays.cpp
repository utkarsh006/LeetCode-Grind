class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>>ans = {{},{}};
        set<int>s1(nums1.begin(),nums1.end());
        set<int>s2(nums2.begin(),nums2.end());

        for(auto x : s1)
        {
            if(!s2.count(x)) ans[0].push_back(x);
        }

        for(auto x : s2)
        {
            if(!s1.count(x)) ans[1].push_back(x);
        }

        return ans;
    }
};

/*
Time complexity:
O(N*log(N))
Space complexity:
O(N)
*/
