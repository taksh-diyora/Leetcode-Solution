class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(head->next == NULL) return head;

        ListNode* curr = head;
        ListNode* nextN = NULL;
        ListNode* prev = NULL;

        while(curr) {
            nextN = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextN;
        }

        return prev;
    }
};