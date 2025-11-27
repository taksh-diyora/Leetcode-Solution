class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> mins(n);
        for(int i=0; i<n; i++){
            int l=i-1;
            int r=i+1;
            int count=0;
            while(l>=0){
                if(nums[l]<nums[i]) count++;
                l--;
            }
            while(r<n){
                if(nums[r]<nums[i]) count++;
                r++;
            }
            mins[i] = count;
        }

        return mins;
    }
};