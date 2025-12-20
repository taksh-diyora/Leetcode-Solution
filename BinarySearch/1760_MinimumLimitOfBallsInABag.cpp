class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations, int mid){
        long long ops = 0;
        for(int i: nums){
            if(i>mid){
                ops+=i/mid-1;
                if(i%mid>0) ops++;
            }
        }
        return ops<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = INT_MIN;

        for(int i: nums){
            r = max(r, i);
        }
        int res = r;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(isPossible(nums, maxOperations, mid)){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return res;
    }
};