/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *curr = head;
        ListNode *small = new ListNode(0);
        ListNode *smalltail=small;
        ListNode *big = new ListNode(0);
        ListNode *bigtail = big;

        while(curr){
            if(curr->val < x){
                smalltail->next=new ListNode(curr->val);
                smalltail = smalltail->next;
            }else{
                bigtail->next=new ListNode(curr->val);
                bigtail = bigtail->next;
            }
            curr = curr->next;
        }
        smalltail->next=big->next;
        return small->next;
    }
};