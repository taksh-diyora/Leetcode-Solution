class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        long long windows = 1;

        for(int i=1; i<n; i++){
            if(prices[i-1]-1 == prices[i]){
                windows++;
            }else{
                ans+= (windows*(windows+1))/2;
                windows = 1;
            }
        }

        return ans+(windows*(windows+1))/2;
    }
};