class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        ListNode dummy(0, head);
        ListNode* temp = &dummy;

        while(temp && temp->next){
            if(temp->next->val == val){
                temp->next = temp->next->next;
            }else
                temp = temp->next;
        }

        return dummy.next;
    }
};