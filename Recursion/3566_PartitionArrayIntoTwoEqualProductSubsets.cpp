class Solution {
public:
    bool solve(vector<int>& nums, long long target, long long s1, long long s2, int i){
        if(s1 > target || s2 > target) return false;
        if(s1 == target && s2 == target && i == nums.size()) return true;
        if(i == nums.size()) return false;
        return (solve(nums, target, s1*nums[i], s2, i+1) || solve(nums, target, s1, s2*nums[i], i+1));
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return solve(nums, target, 1, 1, 0);
    }
};