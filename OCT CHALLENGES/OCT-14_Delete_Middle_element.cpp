// Explanation:
/*The Approch is to use two pointer concept one is slow and another one is fast
    Slow pointer will move one node at each iteration  while fast will move two node with each iterartion
    i.e when the fast reached at NULL pointer the slow will be at MIDDLE NODE and will be delete that node.
    TIME Complexity: O(n)
    SPACE Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

 // Function that deletes the middle of the stack of size n. Current is current 
 // position we’re on 
void deleteMiddle(stack<int> &s, int n,int current)
{
   // If stack becomes empty or all items already are traversed
   if (s.empty() || current == n)
     return;
 
   // Remove current item
   int x = s.top();
   s.pop();
 
   // Call for removing the other items
   deleteMiddle(s, n, current+1);
 
   // Push all the elements back other than the middle one
   if (current != n/2)
     s.push(x);
}

int main()
{
    stack<int> s;
 
    //push elements into the stack
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    int current = 0;
    deleteMiddle(s, s.size(),current);
 
    // Printing stack after deletion of the middle element.
    while (!s.empty())
    {
        int p = s.top();
        s.pop();
        cout << p << " ";
    }
    return 0;
   
}
