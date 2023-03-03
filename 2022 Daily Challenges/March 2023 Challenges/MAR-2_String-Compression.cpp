// Question No. - 443. String Compression
// Link : https://leetcode.com/problems/string-compression/

// Approach :
// Here are the steps:

// 1) Initialize two pointers i and j to the first element of the array.
// 2) Initialize a count variable to 1 and a result string s to empty.
// 3) Iterate through the array from i = 0 to i < chars.size().
// 4) If chars[i] is equal to chars[j], increment the count variable.
// 5) If chars[i] is not equal to chars[j], append chars[j] and its count to s (if count > 1), and reset the count to 1. Set j to i.
// 6) After the loop, append chars[j] and its count to s (if count > 1).
// 7) If the length of s is longer than chars, copy the characters from s to chars.
// 8) Return the length of chars.

// Complexity
// Time complexity:
// The time complexity of this approach is O(n), where n is the length of the input array chars, since we iterate through the array only once.

// Space complexity:
// The space complexity is O(1), since we use only constant extra space.


// Code :
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;
        char curr = chars[0];
        int count = 1;
        string s;
        for (int i = 1; i <= chars.size(); i++) {
            if (i < chars.size() && chars[i] == curr) {
                count++;
            } else {
                s.push_back(curr);
                if (count > 1) {
                    string str = to_string(count);
                    for (char c : str) {
                        s.push_back(c);
                    }
                }
                curr = i < chars.size() ? chars[i] : 0;
                count = 1;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};
