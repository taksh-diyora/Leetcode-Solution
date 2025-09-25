class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* newHead = new ListNode();
        ListNode* newTail = newHead;
        int sum = 0;
        while(temp){
            if(temp->val!=0){
                sum+=temp->val;
            }else{
                ListNode* newNode = new ListNode(sum);
                sum=0;
                newTail->next = newNode;
                newTail=newTail->next;
            }
            temp = temp->next;
        }
        return newHead->next;
    }
};