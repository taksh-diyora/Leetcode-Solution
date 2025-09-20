class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp->next){
            ListNode* newNode = new ListNode(gcd(temp->val, temp->next->val), temp->next);
            temp->next=newNode;
            temp = temp->next->next;
        }
        return head;
    }
};