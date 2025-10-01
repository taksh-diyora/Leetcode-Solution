class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(head1 && head2){
            if(head1->val>head2->val){
                temp->next=head2;
                head2=head2->next;
            }else{
                temp->next=head1;
                head1=head1->next;
            }
            temp=temp->next;
        }

        if(head1) temp->next = head1;
        if(head2) temp->next = head2;
        
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = nullptr;
        for(int i=0; i<n; i++){
            head=mergeTwoLists(lists[i], head);
        }
        return head;
    }
};