class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        vector<int> d(n+1, 0);
        for(int i=0; i<n; i++){
            d[i+1] = d[i] + (nums[i] == target);
        }

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int len = j-i+1;
                int cnt = d[j+1] - d[i];
                if(cnt*2>len) ans++;
            }
        }
        return ans;
    }
};