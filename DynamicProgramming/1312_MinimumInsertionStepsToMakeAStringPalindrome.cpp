class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s, int l, int r){
        if(l == r) return 1;
        if(l > r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        return dp[l][r] = s[l]==s[r]?2+solve(s, l+1, r-1):max(solve(s, l+1, r), solve(s, l, r-1));
    }
    int minInsertions(string s) {
        dp.assign(s.size(), vector<int>(s.size(), -1));
        return s.size() - solve(s, 0, s.size() - 1);
    }
};