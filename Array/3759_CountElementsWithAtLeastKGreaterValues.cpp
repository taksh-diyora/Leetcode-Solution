class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        if(k==0) return n;
        
        for(int i=n-1-k; i>=0; i--){
            if(nums[i]==nums[i+1]) continue;
            return i+1;
        }

        return 0;
    }
};