class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int x = horizontalCuts[0];
        int y = verticalCuts[0];
        
        for(int i = 1; i <horizontalCuts.size(); ++i)
            x = max(x, horizontalCuts[i] - horizontalCuts[i-1]);
        
        for(int i = 1; i < verticalCuts.size(); ++i)
            y = max(y, verticalCuts[i] - verticalCuts[i-1]);
        
        x = max(x, h -  horizontalCuts[ horizontalCuts.size()-1]);
        y = max(y, w -  verticalCuts[ verticalCuts.size()-1]);
        
        int mod = 1e9+7;
        return ((long) x*(long)y)%mod;
    }
};
