class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int m, int i){
        if(i == m) return nums[i];
        if(i < m) return 0;
        int state = (m==0?0:1);
        if(dp[state][i]!=-1) return dp[state][i];

        int twoStep = nums[i] + solve(nums, m, i-2);
        int threeStep = nums[i] + solve(nums, m, i-3);

        return dp[state][i] = max(twoStep, threeStep);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        if (n == 3){
            return max({nums[0], nums[1], nums[2]});
        }

        dp.assign(2, vector<int>(n, -1));
        return max({solve(nums, 0, n-2), solve(nums, 1, n-1), solve(nums, 0, n-3)});
    }
};