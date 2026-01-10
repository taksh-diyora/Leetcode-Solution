class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<int, vector<int>> mp = {
        {0, {4, 6}},
        {1, {6, 8}},
        {2, {7, 9}},
        {3, {4, 8}},
        {4, {0, 3, 9}},
        {6, {0, 1, 7}},
        {7, {2, 6}},
        {8, {1, 3}},
        {9, {4, 2}},
        {0, {4, 6}}
    };
    int mod = 1e9 + 7;
    int solve(int n, int i){
        if(n == 0) return 1;
        if(dp[n][i] != -1) return dp[n][i];
        int ans = 0;
        for(int val: mp[i]){
            ans = (ans + solve(n-1, val))%mod;
        }

        return dp[n][i] = ans;
    }
    int knightDialer(int n) {
        int total = 0;
        dp.assign(n+1, vector<int>(10, -1));
        for(int i=0; i<=9; i++){
            total = (total + solve(n-1, i))%mod;
        }

        return total;
    }
};