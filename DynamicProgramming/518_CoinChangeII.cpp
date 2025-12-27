class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount+1, 0);
        dp[0] = 1;
        for(int c: coins){
            for(int i=c; i<=amount; i++){
                dp[i] = dp[i] + dp[i-c];
            }
        }

        return static_cast<int>(dp[amount]);
    }
};