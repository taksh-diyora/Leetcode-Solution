class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> prime(n, true);
        prime[0]=prime[1]=false;
        for(int i=2; i*1LL*i<n; i++){
            if(prime[i]){
                for(int j=i*i; j<n; j+=i){
                    prime[j]=false;
                }
            }
        }
        int count = 0;
        for(bool k: prime){
            if(k) count++;
        }
        return count;
    }
};