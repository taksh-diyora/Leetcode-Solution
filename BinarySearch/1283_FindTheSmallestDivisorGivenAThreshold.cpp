class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int mid){
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i]/mid;
            if(nums[i]%mid > 0) sum++;
            if(threshold < sum) return false;
        }

        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = INT_MIN;
        int ans = 0;
        for(int i: nums){
            r = max(i, r);
        }
        while(l<=r){
            int mid = l + (r-l)/2;

            if(isPossible(nums, threshold, mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};