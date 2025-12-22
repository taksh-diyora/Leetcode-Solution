class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9+7;
        int n = nums.size();

        vector<int> sqr(n, 1);
        for(int i=1; i<n; i++){
            sqr[i] = (sqr[i-1]*2)%mod;
        }
        int l = 0;
        int r = n-1;
        int res = 0;

        while(l<=r){
            if(nums[l]+nums[r]<=target){
                res = (res + sqr[r-l])%mod;
                l++;
            }else{
                r--;
            }
        }

        return res;
    }
};