class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }

        vector<ListNode*> vec;
        temp = head;
        int partSize = count/k;
        int extra = count%k;
        
        for(int i=0; i<k; i++){
            ListNode* nhead = temp;
            int currSize = partSize + (extra>0?1:0);
            extra--;

            for(int j=0; j<currSize - 1; j++){
                if(temp){
                    temp = temp->next;
                }
            }

            if(temp){
                ListNode* nxtPart = temp->next;
                temp->next=nullptr;
                temp = nxtPart;
            }

            vec.push_back(nhead);
        }

        return vec;
    }
};