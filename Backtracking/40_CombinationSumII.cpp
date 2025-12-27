class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& curr, int sum, int index){
        if(sum == target){
            res.push_back(curr);
            return;
        }
        if(sum > target){
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates, target, res, curr, sum+candidates[i], i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;

        backtrack(candidates, target, res, curr, 0, 0);
        return res;
    }
};