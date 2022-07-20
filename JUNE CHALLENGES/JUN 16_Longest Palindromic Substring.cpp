class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxlen = 1;//its because we'll have atleast one element as the longest palindrome


        for(int i = 0; i < n; i++) 
        {
            //finding the longest palindrome of even length
            int left = i;
            int right = i+1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if((right-left+1) > maxlen) 
                {
                    //since we have found a palindromic substring that has a greater length than the previou palindromic substring
                    //so increase the maxLength 
                    //and move the start pointer to the starting of the new palindromic substring
                    maxlen = right - left + 1;
                    start = left; 
                }
                left--;
                right++;
            }
            
            //finding the longrest palindrome of odd length
            left = i-1;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                if((right-left+1) > maxlen) 
                {
                    maxlen = right-left+1;
                    start =left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxlen);
    }
};
