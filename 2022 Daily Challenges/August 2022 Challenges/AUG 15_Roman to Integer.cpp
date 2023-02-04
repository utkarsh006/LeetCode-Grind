/*
Problem:
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example:
            Input: s = "LVIII"
            Output: 58
            Explanation: L = 50, V= 5, III = 3.

            Input: s = "MCMXCIV"
            Output: 1994
            Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/*
Approach - Using Hashmap

--Store in hashmap all the 7 roman numerals along with their values.

-- We will add Roman numerals in the result , they will be subtractive only when a smaller number appreas before a larger number . Ex: IV (which is 4)

-- Therefore we will iterate backwards from the right side towards the left and result will store the value of last element.

--So we will add every letter in result until we get a letter which is smaller than its next letter then we will subtract it from result.
*/

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> mp;
        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});

        int n = s.size();
        int result = mp[s[n - 1]];
        // iterate backwards
        for (int i = n - 2; i >= 0; i--)
        {
            // if current letter is greater than its next letter then add it's value in result (Ex:VI)
            if (mp[s[i]] >= mp[s[i + 1]])
            {
                result += mp[s[i]];
            }
            // otherwise if current letter is smaller than its next letter then subtract its value from result. (Ex: IV)
            else
                result -= mp[s[i]];
        }
        return result;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1) as hashmap will contain only 7 values for every testcase not more than that
*/

/*
Approach - Using Switch Case

-- Approach is same that keep on adding the letters in the result until we find a letter whose value is smaller than the next one.

-- Here we will use switch case instead of hashmap, so whenever we want value of any letter then through recursion we will get that value.
*/

class Solution
{
public:
    int help(char str)
    {
        switch (str)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s)
    {
        int n = s.size();
        int sum = help(s[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            // if current letter is greater than its next letter then add it's value in result (Ex:VI)
            if (help(s[i + 1]) <= help(s[i]))
            {
                sum += help(s[i]);
            }
            // otherwise if current letter is smaller than its next letter then subtract its value from result. (Ex: IV)
            else
                sum -= help(s[i]);
        }
        return sum;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/