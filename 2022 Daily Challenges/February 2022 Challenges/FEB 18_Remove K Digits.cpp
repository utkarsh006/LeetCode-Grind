/*
Problem: Remove K Digits

Given string num representing a non-negative integer num, and an integer k,
return the smallest possible integer after removing k digits from num.

Example:

        Example 1:

        Input: num = "1432219", k = 3
        Output: "1219"
        Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
         which is the smallest.

        Example 2:

        Input: num = "10200", k = 1
        Output: "200"
        Explanation: Remove the leading 1 and the number is 200. Note that the output
        must not contain leading zeroes.

        Example 3:

        Input: num = "10", k = 2
        Output: "0"
        Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/*
Approach

1. We will use a stack to store the characters, therefore initially when stack is empty we
   will push the element in stack.

2. Then from next element when stack will not be empty we will use a while loop to check if the top
   element of stack is greater than the current array element , if so then we will pop the top element from
   stack and decrement k.

3. We will pop the greater elements from stack until k>0 if k==0 then we will not pop anymore even
   if stack top is greater.

4. And we'll push every element in stack.

5. Once we traverse all the characters through for loop we will exit from for loop, now if k>0 that means
   we still need to pop elements from stack, so we'll pop elements from stack and will decrement k until k!=0

6. Now if stack is empty return "0" means our smallest possible integer will be 0.

7. If our stack is not empty then we will store the elements in temp string and will pop elements from stack
   until stack is not empty.

8.Now reverse the temp string because when we popped characters from stack they are stored in reversed order.

9.As been told we don't need leading 0's like we dont want 0200 instead we want 200, so for that we will
 check that while temp[i]== '0' we will increment i and will return substr of i if it is not empty.

10. Edge Case: If k>= n then it means we can have only "0" as smallest string.
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        int n = num.size();
        string temp = "";
        if (k >= n)
            return "0";
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                st.push(num[i]);
            else
            {
                while (!st.empty() && st.top() > num[i] && k != 0)
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }

        while (k > 0)
        {
            st.pop();
            k--;
        }
        if (st.empty())
            return "0";
        while (!st.empty())
        {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        int i = 0;
        while (temp[i] == '0')
            i++;

        return (temp.substr(i) == "") ? "0" : temp.substr(i);
    }
};

/*
Time Complexity: O(N) as we only traversing the string for once
Space Complexity: O(N) as we will store maximum of n digits in our string
*/