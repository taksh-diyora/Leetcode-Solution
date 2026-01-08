class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums1, vector<int>& nums2, int i1, int i2){
        if(i1 == nums1.size() || i2 == nums2.size()){
            return -(1e9+7);
        }
        if(dp[i1][i2]!=-1) return dp[i1][i2];

        int ans = nums1[i1]*nums2[i2];

        ans = max(ans, nums1[i1]*nums2[i2] + solve(nums1, nums2, i1+1, i2+1));
        ans =  max(ans, solve(nums1, nums2, i1+1, i2));
        ans = max(ans, solve(nums1, nums2, i1, i2+1));

        return dp[i1][i2] = ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.assign(nums1.size(), vector<int>(nums2.size(), -1));
        return solve(nums1, nums2, 0, 0);
    }
};