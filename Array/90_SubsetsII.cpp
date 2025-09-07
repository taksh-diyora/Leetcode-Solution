class Solution {
public:
    void pushF(int i, vector<int> &ds, vector<int> &nums, int n, set<vector<int>>& subs){
        if(i==n){
            subs.insert(ds);
            return;
        }

        ds.push_back(nums[i]);
        pushF(i+1, ds, nums, n, subs);
        ds.pop_back();

        pushF(i+1, ds, nums, n, subs);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        set<vector<int>> subs;
        int n = nums.size();
        pushF(0, ds, nums, n, subs);
        return vector<vector<int>>(subs.begin(), subs.end());
    }
};