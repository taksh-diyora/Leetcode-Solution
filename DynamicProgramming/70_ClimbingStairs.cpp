class Solution {
public:
    int fn(int n, int i, vector<int>& dp){
        if(i == n){
            return 1;
        }
        if(i > n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        return dp[i] = fn(n, i+1, dp) + fn(n, i+2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return fn(n, 0, dp);
    }
};