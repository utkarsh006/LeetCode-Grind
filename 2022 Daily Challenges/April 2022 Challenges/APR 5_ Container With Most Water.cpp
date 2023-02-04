class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int start = 0;
        int end = n-1;
        int area = 0;
        
           while(start<end)
           {
               area = max(area, min(height[start],height[end]) * (end-start));
               
               if(height[start]<height[end])
                   start++;
               else
                   end--;
           }
        return area;
    }
};
