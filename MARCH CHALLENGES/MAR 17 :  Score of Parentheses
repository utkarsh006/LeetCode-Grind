class Solution {
public:
    int scoreOfParentheses(string s) 
    {  
        int n = s.size();
        stack<int> st;
        st.push(0);
        
          for(int i=0;i<n;i++)
          {
              if(s[i]=='(')
                  st.push(0);
        
              else
              {
                 int innerdepth = st.top();
                   st.pop();
              
                 int outerdepth = st.top();
                   st.pop();
              
                 st.push(outerdepth + max(2*innerdepth,1));
              }
          }
       return st.top(); 
    }
};
