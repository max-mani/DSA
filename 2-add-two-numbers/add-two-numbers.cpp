class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* out = head;
        int c = 0, t = 0;
        while (l1 || l2 || c) {
            t = c;
            if (l1) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                t += l2->val;
                l2 = l2->next;
            }
            int n = t % 10;
            c = t / 10;
            head->next = new ListNode(n);
            head = head->next;
        }
        return out->next;
    }
};