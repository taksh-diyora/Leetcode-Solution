class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> ans;

        sort(nums.begin(), nums.end());
        for(int i: nums){
            if(ans.empty() || ans.back().first != i){
                ans.push_back(make_pair(i, 1));
            }else{
                ans.back().second++;
            }
        }

        sort(ans.begin(), ans.end(), [](pair<int, int> a,pair<int, int> b){
            return a.second > b.second;
        });

        vector<int> vals;
        for(int i=0; i<k; i++){
            vals.push_back(ans[i].first);
        }

        return vals;
    }
};