class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& comb, vector<int>& candidates, int target, int sum, int idx){
        if(sum == target){
            res.push_back(comb);
            return;
        }

        if(sum > target || idx >= candidates.size()){
            return;
        }

        comb.push_back(candidates[idx]);
        backtrack(res, comb, candidates, target, sum+candidates[idx], idx);
        comb.pop_back();
        backtrack(res, comb, candidates, target, sum, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(res, comb, candidates, target, 0, 0);
        return res;
    }
};