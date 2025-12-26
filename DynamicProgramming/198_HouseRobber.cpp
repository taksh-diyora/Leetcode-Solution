class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int>& nums){
        if(i == 0) return nums[0];
        if(i < 0) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int TwoStep = nums[i] + solve(i-2, nums);
        int ThreeStep = nums[i] + solve(i-3, nums);

        return dp[i] = max(TwoStep, ThreeStep);
    }
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        dp.assign(n+1, -1);

        return max(solve(n-1, nums), solve(n, nums));
    }
};