class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // if str p size is greater than str s then result = empty string
        if (p.size() > s.size())
        {
            return {};
        }
        // initialize two vectors of size 26, freq and count, to store the frequency of each letter in p and a sliding window in s
        vector<int> freq(26, 0), ans, count(26, 0);
        int n = p.size();
        // calculating freq of each letter in P
        for (int i = 0; i < n; i++)
        {
            freq[p[i] - 'a']++;
            count[s[i] - 'a']++;
        }

        // if first window contains anagram
        if (freq == count)
        {
            ans.push_back(0);
        }
        // slide the window by 1 each time and update the count vector
        for (int i = n; i < s.size(); i++)
        {
            // decrease the frequency of the letter that is out of the window
            count[s[i - n] - 'a']--;
            // increase the frequency of the letter that just enters the window
            count[s[i] - 'a']++;
            // check if the current window is an anagram of p
            if (count == freq)
            {
                ans.push_back(i - n + 1);
            }
        }
        return ans;
    }
};