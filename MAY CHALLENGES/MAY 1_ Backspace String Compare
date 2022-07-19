class Solution {
public:
    string actualString(string str)
    {
        int len = str.length();
        string ans = "";
        int i = len - 1, backspace = 0;
        while(i >= 0)
        {
            if(str[i] == '#')
            {
                backspace++;
            }
            else
            {
                if(backspace == 0)
                {
                    ans += str[i];
                }
                if(backspace > 0) backspace--;
            }
            i--;
        }
        return ans;
    }
    
    bool backspaceCompare(string s, string t)
    {
        s = actualString(s);        
        t = actualString(t);
        if(s == t) return true;
        return false;
    } 
};
