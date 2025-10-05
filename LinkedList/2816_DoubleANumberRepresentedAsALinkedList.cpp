class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextN = nullptr;
        while(curr!=nullptr){
            nextN = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextN;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head = rev(head);
        int carry = 0;
        ListNode* temp = head;
        while(temp){
            int val = temp->val;
            val = val*2+carry;
            carry = val/10;
            temp->val = val%10;
            if(temp->next==nullptr && carry == 1){
                ListNode* newNode = new ListNode(1);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return rev(head);
    }
};