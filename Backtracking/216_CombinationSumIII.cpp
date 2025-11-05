class Solution {
public:
    void solve(int idx, vector<vector<int>>&ans, vector<int>&current, vector<int>&arr, int k, int n){
        if(n == 0 && k == 0){
            ans.push_back(current);
            return;
        }
        
        if(idx == 9) return;

        if(arr[idx] <= n){
            current.push_back(arr[idx]);
            solve(idx+1, ans, current, arr, k-1, n-arr[idx]);
            current.pop_back();
        }

        solve(idx+1, ans, current, arr, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>current;
        solve(0, ans, current, arr, k, n);
        return ans;
    }
};