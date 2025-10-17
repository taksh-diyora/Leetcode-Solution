class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int count=0;
        unordered_set<int> values(nums.begin(), nums.end());
        ListNode* temp = head;
        
        while(temp){
            if(values.count(temp->val)){
                while(temp && values.count(temp->val)){
                    temp = temp->next;
                }
                count++;
            }else temp = temp->next;
        }

        return count;
    }
};