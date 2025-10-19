class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long count = 0;
        stack<int> stk;
        for(int i=0; i<nums.size(); i++){
            while(!stk.empty() && nums[stk.top()]<nums[i]){
                stk.pop();
                if(!stk.empty()){
                    count++;
                }
            }
            stk.push(i);
        }

        return count;
    }
};