class Solution {
public:
    void pushF(int i, vector<int> &ds, vector<int> &nums, int n, vector<vector<int>>& subs){
        if(i==n){
            subs.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        pushF(i+1, ds, nums, n, subs);
        ds.pop_back();

        pushF(i+1, ds, nums, n, subs);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> subs;
        int n = nums.size();
        pushF(0, ds, nums, n, subs);
        return subs;
    }
};