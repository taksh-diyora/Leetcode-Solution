class Solution {
public:
    vector<int> cuts;
    vector<vector<int>> dp;
    int solve(int i, int j){
        if(j-i<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minCost = INT_MAX;
        

        for(int k=i+1; k<j; k++){
            int currCost = cuts[j] - cuts[i] + solve(i, k) + solve(k, j);

            minCost = min(minCost, currCost);
        }

        return dp[i][j] = minCost;
    }
    int minCost(int n, vector<int>& cut) {
        cuts = cut;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        dp.assign(m, vector<int>(m, -1));

        return solve(0, m-1);
    }
};