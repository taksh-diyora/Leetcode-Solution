class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==nullptr) return {-1, -1};
        ListNode* temp = head;
        int firstCrit = -1;
        int prevCrit = -1;
        int minD = 1000000;
        int index = 1;
        while(temp->next->next!=nullptr){
            if((temp->next->val < temp->next->next->val && temp->next->val < temp->val)||(temp->next->val > temp->next->next->val && temp->next->val > temp->val)){
                if(firstCrit==-1){
                    firstCrit = index;
                }else{
                    minD = min(minD, index-prevCrit);
                }
                prevCrit = index;
            }
            index++;
            temp = temp->next;
        }
        if(firstCrit==-1 || firstCrit == prevCrit) return {-1, -1};
        return {minD, prevCrit-firstCrit};
    }
};