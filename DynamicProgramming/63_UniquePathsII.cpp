class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& obstacleGrid){
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int tb = 0;
        if(i-1>=0) tb = solve(i-1, j, obstacleGrid);
        int rl = 0;
        if(j-1>=0) rl = solve(i, j-1, obstacleGrid);

        return dp[i][j] = tb+rl;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp.assign(m+1, vector<int>(n+1, -1));

        return solve(m-1, n-1, obstacleGrid);
    }
};