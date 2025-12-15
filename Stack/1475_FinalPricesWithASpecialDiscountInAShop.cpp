class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res = prices;
        stack<int> s;

        for(int j=0; j<n; j++){
            while(!s.empty() && prices[j]<=prices[s.top()]){
                res[s.top()] -= prices[j];
                s.pop();
            }
            s.push(j);
        }

        return res;
    }
};