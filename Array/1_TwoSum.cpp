class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> a;
        for(int i = 0; i<nums.size(); i++){
            int sv = target - nums[i];
            if(a.find(sv)!=a.end()){
                return {i, a[sv]};
            }
            a[nums[i]] = i;
        }
        return {};
    }
};