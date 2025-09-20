class Solution {
public:
    void swap(ListNode* head){
        if(!head || !head->next) return;
        ListNode* newHead = head->next;
        ListNode* temp = newHead->next;
        newHead->next=head;
        head->next=temp;
        swapPairs(temp);
    }
    ListNode* swapPairs(ListNode* head) {
        swap(head);
        return head;
    }
};