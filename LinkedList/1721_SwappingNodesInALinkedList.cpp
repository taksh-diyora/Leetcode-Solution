class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        vector<int> newVals;
        while(temp){
            newVals.push_back(temp->val);
            temp=temp->next;
        }
        swap(newVals[k-1], newVals[newVals.size()-k]);
        ListNode* newHead = new ListNode();
        ListNode* newTra = newHead;
        for(int i=0; i<newVals.size(); i++){
            ListNode* newNode = new ListNode(newVals[i]);
            newTra->next=newNode;
            newTra = newTra->next;
        }
        return newHead->next;
    }
};