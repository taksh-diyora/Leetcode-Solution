class Solution {
public:
    vector<vector<int>> dp;
    int solve(int m, int n, int i, int j){
        if(m-1 == i && n-1==j){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int tb = 0;
        if(i+1<m) tb = solve(m, n, i+1, j);
        int rl = 0;
        if(j+1<n) rl = solve(m, n, i, j+1);

        return dp[i][j] = rl+tb;
    }
    int uniquePaths(int m, int n) {
        dp.assign(m+1, vector<int>(n+1, -1));

        return solve(m, n, 0, 0);
    }
};