class Solution {
public:
    int LIS(vector<pair<int, int>>& nums){
        vector<int> tails;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i].second;
            auto it = lower_bound(tails.begin(), tails.end(), num);

            if(it == tails.end()){
                tails.push_back(num);
            }else{
                *it = num;
            }
        }

        return tails.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int,int>> ep;
        for(auto e: envelopes){
            ep.push_back({e[0], e[1]});
        }
        sort(ep.begin(), ep.end(), [](pair<int,int> a, pair<int,int> b){
            if(a.first!=b.first){
                return a.first<b.first;
            }
            return a.second>b.second;
        });

        return LIS(ep);
    }
};