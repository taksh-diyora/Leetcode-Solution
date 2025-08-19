class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long strike = 0;
        for(int n: nums){
            if(n==0){
                strike++;
                ans+=strike;
            }else{
                strike=0;
            }
        }
        return ans;
    }
};