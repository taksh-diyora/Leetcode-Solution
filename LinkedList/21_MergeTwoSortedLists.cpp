class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(temp1 && temp2) {
            if(temp1->val < temp2->val) {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }
        if(temp1) temp->next = temp1;
        if(temp2) temp->next = temp2;
        return dummyNode->next;
    }
};