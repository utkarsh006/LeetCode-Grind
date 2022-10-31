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

#include <iostream>
using namespace std;
struct Node {
    int val;
    struct Node* next;
};

int count_nodes(struct Node* head)
{
    int n_count = 0;
    while (head != NULL) {
        head = head->next;
        n_count++;
    }
    return n_count;
}

struct Node* delete_middle(struct Node* head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    struct Node* Head_copy = head;
    // total nodes currently there in the list
    int count = count_nodes(head);
    // position of middle element in the list
    int mid = count / 2;
    // Delete the middle node
    while (mid-- > 1) {
        head = head->next;
    }
    // Delete the middle node
    head->next = head->next->next;
    return Head_copy;
}
void display_List(struct Node* x)
{
    while (x != NULL) {
        cout << x->val << "->";
        x = x->next;
    }
    // Last element points to null
    cout << "NULL\n";
}
Node* newNode(int value)
{
    struct Node* t = new Node;
    t->val = value;
    t->next = NULL;
    return t;
}

int main()
{
    // Adding elements to the empty list
    struct Node* head = newNode(5);
    head->next = newNode(10);
    head->next->next = newNode(15);
    head->next->next->next = newNode(20);
     head->next->next->next->next = newNode(25);
    cout << "Original List" << endl;
    display_List(head);
    head = delete_middle(head);
    cout << "List after deleting the middle element"
 << endl;
    display_List(head);
    return 0;
}