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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int length = 1;
        ListNode* temp = head;
        while(temp->next){
            length++;
            temp=temp->next;
        }

        int pos = k%length;
        if(pos==0){
            return head;
        }
        ListNode* temp2 = head;
        for(int i=1; i<length-pos; i++){
            temp2 = temp2->next;
        }

        ListNode* newHead = temp2->next;
        temp2->next = nullptr;
        temp->next=head;

        return newHead;
    }
};