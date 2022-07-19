class Solution {
private:
    unordered_map<Node *, Node *> map;
public:
    Node *copyRandomList(Node *head, Node *result = nullptr)
    {
        if (!head) return head;
        result = new Node(head->val);
        map[head] = result;
        result->next = copyRandomList(head->next, result->next);
        result->random = map[head->random];
        return result;
    }
};
