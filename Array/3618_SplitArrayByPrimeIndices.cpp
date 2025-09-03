class Solution {
public:
    bool isPrime(int n){
        if(n<2) return false;
        if(n%2==0) return n==2;
        for(int i=3; i*1LL*i<=n; i+=2){
            if(n%i==0) return false;
        }
        return true;
    }

    long long splitArray(vector<int>& nums) {
        long long pS = 0;
        long long npS = 0;
        for(int i=0; i<nums.size(); i++){
            if(isPrime(i)){
                pS += nums[i];
            }else{
                npS += nums[i];
            }
        }
        return (long long)abs(pS-npS);
    }
};