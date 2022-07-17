class Solution {
public:
    
     bool dfs(vector<int> &matchsticks, int i, int left, int top, int right, int down)
     {
          if(i == matchsticks.size())
            return left == top == right == down;
         
         if(matchsticks[i] <= left)
            if(dfs(matchsticks, i + 1, left - matchsticks[i], top, right, down)) return true;
         
        if(matchsticks[i] <= top)
            if(dfs(matchsticks, i + 1, left, top - matchsticks[i], right, down)) return true;
         
        if(matchsticks[i] <= right)
            if(dfs(matchsticks, i + 1, left, top, right - matchsticks[i], down)) return true;
         
        if(matchsticks[i] <= down)
            if(dfs(matchsticks, i + 1, left, top, right, down - matchsticks[i])) return true;
         
         
        return false;
        
     }
    
    bool makesquare(vector<int>& arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        /* accumulate function gives the sum of all elements of array and last parameter
        means that initial value of sum is 0.  */
        
        if(sum%4 !=0) return false;          // square can't be formed
        
        if(arr.size()<4)  return false;
        // if array has less than  4 elements square can't be formed
        
        int side = sum/4;    // each side length
        sort(arr.rbegin(), arr.rend());  // reverse sort
        
        return dfs(arr, 0, side, side, side, side);
          
    }
};
