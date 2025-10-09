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
    ListNode* mergeSortedLists(ListNode* head1, ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;

        ListNode* result = nullptr;

        if(head1->val <= head2->val){
            result = head1;
            result->next = mergeSortedLists(head1->next, head2);
        }else{
            result = head2;
            result->next = mergeSortedLists(head2->next, head1);
        }
        return result;
    }
    ListNode* findMiddle(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head   ;
        ListNode* prev = nullptr;

        while(fast&&fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev){
            prev->next=nullptr;
        }

        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* middle = findMiddle(head);
        ListNode* leftHalf = head;
        ListNode* rightHalf = middle;

        leftHalf = sortList(leftHalf);
        rightHalf = sortList(rightHalf);

        return mergeSortedLists(leftHalf, rightHalf);
    }
};