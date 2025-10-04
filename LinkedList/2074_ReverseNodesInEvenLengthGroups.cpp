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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        int groupsize = 1;
        ListNode* curr = head;
        ListNode* prev = dummy;
        while(curr){
            ListNode* groupStart = curr;
            int count = 0;
            
            while(curr && count<groupsize){
                curr = curr->next;
                count++;
            }

            if(count%2==0){
                ListNode* nextGroup = curr;
                ListNode* temp = groupStart;
                int c = 1;
                while(c<count){
                    temp = temp->next;
                    c++;
                }
                temp->next = nullptr;

                ListNode* newHead = rev(groupStart);
                prev->next = newHead;

                prev=groupStart;
                prev->next = nextGroup;
            }else{
                for(int i=0; i<count; i++){
                    prev = prev->next;
                }
            }
            groupsize++;
        }
        return dummy->next;
    }
};