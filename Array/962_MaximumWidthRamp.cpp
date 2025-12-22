class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> vals;
        int n = nums.size();
        for(int i=0; i<n; i++){
            vals.push_back({nums[i], i});
        }

        sort(vals.begin(), vals.end(), [](pair<int, int> a, pair<int, int> b){
            if(a.first==b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        int maxD = 0;
        int minIndex = vals[0].second;

        for(int i=1; i<n; i++){
            maxD = max(maxD, vals[i].second - minIndex);
            minIndex = min(minIndex, vals[i].second);
        }
        return maxD;
    }
};