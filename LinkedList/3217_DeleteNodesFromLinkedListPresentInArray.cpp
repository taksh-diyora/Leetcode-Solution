class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> m;
        for(int i: nums){
            m[i]=1;
        }
        ListNode* temp = head;
        ListNode* newHead = new ListNode();
        ListNode* temp1 = newHead;
        while(temp){
            if(!m[temp->val]){
                ListNode* newNode = new ListNode(temp->val);
                temp1->next=newNode;
                temp1=temp1->next;
            }
            temp=temp->next;
        }
        return newHead->next;
    }
};