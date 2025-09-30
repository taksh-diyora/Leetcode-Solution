class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp(n-1);
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                temp[j]=(nums[j]+nums[j+1])%10;
            }
            if(n-i-1==1) return temp[0];
            nums = temp;
        }
        return -1;
    }
};