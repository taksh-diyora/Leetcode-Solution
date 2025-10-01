class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};