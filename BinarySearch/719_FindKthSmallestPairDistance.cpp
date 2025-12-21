class Solution {
public:
    int position(vector<int>& nums, int mid, int n){
        int count = 0;
        int left = 0;
        for(int right = 1; right<n; right++){
            while(nums[right] - nums[left] > mid){
                left++;
            }
            count+=right-left;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n-1]-nums[0];
        int ans = -1;

        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(position(nums, mid, n)>=k){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};