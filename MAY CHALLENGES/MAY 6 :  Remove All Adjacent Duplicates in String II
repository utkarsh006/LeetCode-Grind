/* 
- Maintain a continuous frequency count of items.
- Use a stack, push each element in the stack while maintaing continous frequency count.
- If after pushing an element in the stack 
 continousFreqCount[ indexOfLastPushedElement ] == k pop stack k times.
    
- Finally, all of the elements left in the stack will be combined to form our final solution. Concatenate them into a string and reverse the string for obvious reasons.
    
- TC : O(N) because each element will be pushed and popped from the stack only once. */
    
class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        
        int n = s.length();
        vector<int> continousFreqCount(n, 1);
        stack<int> st;
        string ans;
        
        st.push(0);
        
        for(int i = 1; i < n ; i++)
        {
            
            if(!st.empty())
            {
              if(s[st.top()]==s[i]) 
                  continousFreqCount[i] = continousFreqCount[st.top()] + 1;
            }
            
            st.push(i);
            
            if(continousFreqCount[st.top()] == k)
            {
                for(int i = 0 ; i < k ; i++)
                    st.pop();
                
            }
            
        }
        
        while(!st.empty())
        {
            
            ans += s[st.top()];
            st.pop();
            
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
