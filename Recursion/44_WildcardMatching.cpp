class Solution {
public:
    bool solve(string& s, string& p, int sIndex, int pIndex, vector<vector<int>>& dp){
        if(sIndex == s.size() && pIndex == p.size()) return true;

        if(pIndex>=p.size()) return false;
        if(dp[sIndex][pIndex] != -1) return dp[sIndex][pIndex];

        bool res = false;
        
        if(p[pIndex] == '*'){
            res = solve(s, p, sIndex, pIndex+1, dp) || (sIndex < s.size() && solve(s, p, sIndex+1, pIndex, dp));
        }else{
            bool isMatch = sIndex<s.size() && ( s[sIndex] == p[pIndex] || p[pIndex] == '?');

            if(isMatch){
                res = solve(s, p, sIndex+1, pIndex+1, dp);
            }else{
                res = false;
            }
        }

        dp[sIndex][pIndex] = res;
        return res;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(s, p, 0, 0, dp);
    }
};