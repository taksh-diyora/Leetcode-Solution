class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextTemp = nullptr;

        while(curr!=nullptr){
            nextTemp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextTemp;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = rev(slow->next);
        fast = slow->next;
        slow = head;
        int maxV = 0;
        while(fast){
            maxV = max(maxV, slow->val+fast->val);
            slow=slow->next;
            fast=fast->next;
        }
        return maxV;
    }
};