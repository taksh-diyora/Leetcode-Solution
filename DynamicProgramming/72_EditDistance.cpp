class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s, string& p, int i, int j){
        if(i == s.size()){
            return p.size() - j;
        }
        if(j == p.size()){
            return s.size() - i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        if(s[i] == p[j]){
            return dp[i][j] = solve(s, p, i+1, j+1);
        }
        return dp[i][j] = 1 + min({solve(s, p, i, j+1), solve(s, p, i+1, j), solve(s, p, i+1, j+1)});
    }
    int minDistance(string word1, string word2) {
        dp.assign(word1.size(), vector<int>(word2.size(), -1));
        return solve(word1, word2, 0, 0); 
    }
};