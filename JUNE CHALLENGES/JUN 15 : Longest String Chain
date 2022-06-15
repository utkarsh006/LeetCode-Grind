/* Time Complexity : O(n*n), Space Complexity : O(n)

1. At first the array is sorted according to length of the words, so that another word after a word can not be its predecessor.

2. A dp array is declared for storing the maximum number of predecessor present in the array for a word in the array words.

3. An iterative dp is run for each element (curr). In it for each curr a loop is run from start of the array to the curr element (prev) where it checks
if prev is the predecessor of curr using function predecessor() and stores the maximun of dp[curr] and 1+dp[prev]. 
Max is stored because there can be multiple predecessor of curr before it.

4. The ans is updated as max of ans and dp[curr] after each loop so that it store the longest word chain of predecessor and is returned at the end.  */
    
    
class Solution {
public:
    bool predecessor(string &prev, string &curr) 
    {
		int n = prev.size(), m = curr.size();
        
        // as only 1 character can be added to prev to get curr
		if (n+1 != m) 
            return false;

        int i=0, j=0;
		while (j < m) 
        {
			if (prev[i] == curr[j])
            {
				i++, j++;
			}
			else
                j++;
		}

        // if the prev doesn't reach its end then its not predecessor
		return i==n;
	}
    
    //compare function for sorting
    static bool compare (string& first, string& second) {
        return first.size() < second.size();
    }
    
	int longestStrChain(vector<string>& words) 
    {
        
        //1. sorting according to length.
		sort(words.begin(), words.end(), compare);
        
        //2. Declaration of dp
        //Min value of ans and dp element is 1(the word itself).
		vector<int> dp(words.size(), 1);
		int ans = 1; 
        
		//3. Iterative dp
		for (int curr = 0; curr < words.size(); curr++)
        {
			for (int prev = 0; prev < curr; prev++)
            {
				if (predecessor(words[prev], words[curr]))
                {
                    dp[curr] = max(dp[curr], dp[prev]+1);
                }
			}
            
			//4. Updating ans
			ans = max(ans, dp[curr]);
		}
		return ans;
	}
};
