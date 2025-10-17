class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newHead = new ListNode(0, head);
        ListNode* left = newHead;
        ListNode* right = left->next;

        while(right){
            if(right->next && right->val == right->next->val){
                int dupVal = right->val;
                while(right && right->val == dupVal){
                    right = right->next;
                }
                left->next = right;
            }else{
                left = right;
                right = right->next;
            }
        }
        return newHead->next;
    }
};