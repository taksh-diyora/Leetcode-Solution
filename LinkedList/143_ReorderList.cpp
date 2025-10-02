class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = slow->next;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* b = slow->next;
        slow->next = nullptr;
        ListNode* node = nullptr;

        while (b) {
            ListNode* temp = b->next;
            b->next = node;
            node = b;
            b = temp;
        }

        ListNode* a = head;
        b = node;
        while(b){
            ListNode* temp1 = a->next;
            ListNode* temp2 = b->next;
            a->next = b;
            b->next = temp1;
            a = temp1;
            b = temp2;
        }
    }
};