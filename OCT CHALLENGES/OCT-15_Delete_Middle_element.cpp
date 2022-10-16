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
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head, *fast = head;
        ListNode *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};