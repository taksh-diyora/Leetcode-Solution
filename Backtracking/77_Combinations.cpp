class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& comb, vector<vector<int>>& res){
        if(comb.size()==k){
            res.push_back(comb);
            return;
        }

        for(int num = start; num <= n; num++){
            comb.push_back(num);
            backtrack(num + 1, n, k, comb, res);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> res;
        backtrack(1, n, k, comb, res);
        return res;
    }
};