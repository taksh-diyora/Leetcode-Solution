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
    ListNode* rev(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextN = nullptr;

        while(curr!=nullptr){
            nextN = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextN;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prevGroupTail = &dummy;
        while(true){
            ListNode* kth = prevGroupTail;
            for(int i=0; i<k && kth; i++){
                kth = kth->next;
            }
            if(!kth) break;
            ListNode* nextGroupStart = kth->next;

            ListNode* groupStart = prevGroupTail->next;
            kth->next = nullptr;
            prevGroupTail->next = rev(groupStart);

            groupStart->next = nextGroupStart;
            prevGroupTail = groupStart;
        }
        return dummy.next;
    }
};