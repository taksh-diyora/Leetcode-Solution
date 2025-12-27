class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);
        int sum = 0;

        int maxV = INT_MIN;
        int minV = INT_MAX;

        for(int i=0; i<n; i++){
            maxV = max(maxV, nums[i]);
            pref[i] = maxV;
            minV = min(minV, nums[n-i-1]);
            suff[n-i-1] = minV;
        }

        for(int i=1; i<n-1; i++){
            if(nums[i]<suff[i+1] && nums[i]>pref[i-1]){
                sum+=2;
            }else if(nums[i]>nums[i-1] && nums[i]<nums[i+1]){
                sum+=1;
            }
        }

        return sum;
    }
};