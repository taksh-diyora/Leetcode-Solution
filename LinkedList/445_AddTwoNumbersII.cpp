class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextN = nullptr;

        while(curr){
            nextN = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextN;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);
        l2 = rev(l2);
        int carry = 0;
        ListNode* newNode = new ListNode(0);
        ListNode* current = newNode;

        while(l1!=NULL||l2!=NULL||carry!=0){
            int x = (l1!=NULL)?l1->val:0;
            int y = (l2!=NULL)?l2->val:0;

            int sum = x+y+carry;

            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;

            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        return rev(newNode->next);
    }
};