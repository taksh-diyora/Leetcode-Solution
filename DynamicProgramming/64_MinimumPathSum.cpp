class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];
        int bt = INT_MAX;
        if(i>0) bt = grid[i][j] + solve(i-1, j, grid);
        int rl = INT_MAX;
        if(j>0) rl = grid[i][j] + solve(i, j-1, grid);

        return dp[i][j] = min(bt, rl);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, grid);
    }
};