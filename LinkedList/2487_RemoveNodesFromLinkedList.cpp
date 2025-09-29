class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextTemp = nullptr;

        while(curr!=nullptr){
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;

        head = reverse(head);
        ListNode* slow = head;
        ListNode* fast = head->next;
        int maxV = head->val;

        while(fast){
            if(fast->val>=maxV){
                slow->next=fast;
                slow=slow->next;
                maxV = fast->val;
            }
            fast = fast->next;
        }

        slow->next=nullptr;

        head = reverse(head);
        return head;
    }
};