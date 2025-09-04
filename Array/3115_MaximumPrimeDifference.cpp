class Solution {
public:
    bool isPrime(int n){
        if(n<2) return false;
        if(n%2==0) return n==2;
        for(int i = 3; i*1LL*i<=n; i+=2){
            if(n%i==0) return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int minI = -1;
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(isPrime(nums[i])){
                if(minI == -1) minI = i;
                ans = max(ans, i-minI);
            }
        }
        return ans;
    }
};