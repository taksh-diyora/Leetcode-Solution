class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> psf(n), psb(n);
        int pf = 0, pb = 0;
        for(int i=0; i<n; i++){
            pf+=nums[i];
            psf[i] = pf;

            pb+=nums[n-1-i];
            psb[n-i-1] = pb;
        }
        int count = 0;
        for(int i=1; i<n; i++){
            if((psf[i-1]-psb[i])%2==0) count++;
        }
        return count;
    }
};