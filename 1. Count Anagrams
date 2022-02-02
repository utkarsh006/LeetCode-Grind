#include <bits/stdc++.h>
using namespace std;

int anagram(string s, string p)
{
    int k = p.length();
    int i = 0, j = 0;
    unordered_map<char, int> mp;
    
    for (int i=0; i<k; i++)
    {
        mp[p[i]]++;
    }
    
    int count = mp.size();
    int ans = 0;
    
    while (j < s.length())
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]] -= 1;
            if (mp[s[j]] == 0)
            {
                count -= 1;
            }
        }
        
        if (j-i+1 < k)
        {
            j++;
        }
        
        else if (j-i+1 == k)
        {
            if (count == 0)
            {
                ans += 1;
            }
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]] += 1;
                if (mp[s[i]] == 1)
                {
                    count += 1;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    string s, p;
    cout<<"ENTER THE STRING : ";
    getline(cin,s);
    cout<<"\n";
    
    cout<<"ENTER THE PATTERN : ";
    getline(cin,p);
    cout<<"\n";

    cout << anagram(s,p);
    return 0;
}
