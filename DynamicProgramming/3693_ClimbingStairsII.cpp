class Solution {
public:
    vector<int> dp;
    int solve(int i,vector<int>& costs){
        if(i <= 0) return 0;
        if(dp[i]!=-1) return dp[i];
        int OneStep = 1 + costs[i-1] + solve(i-1, costs);
        int TwoStep = 4 + costs[i-1] + solve(i-2, costs);
        int ThreeStep = 9 + costs[i-1] + solve(i-3, costs);

        int minV = min(OneStep, TwoStep);
        minV = min(minV, ThreeStep);

        return dp[i] = minV;
    }
    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n+1, -1);
        return solve(n, costs);
    }
};