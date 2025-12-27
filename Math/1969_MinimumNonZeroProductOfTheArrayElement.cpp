class Solution {
public:
    int mod = 1e9+7;
    long long power(long long base, long long n){
        long long res = 1;
        base = base%mod;
        
        while(n > 0){
            if(n%2==1) res = (res*base)%mod;
            n/=2;
            base = (base*base)%mod;
        }

        return res;
    }
    int minNonZeroProduct(int p) {
        if(p == 1) return 1;

        long long maxValue = power(2, p);
        long long term1 = (maxValue - 1 + mod)%mod;

        long long baseValue = (maxValue-2+mod)%mod;
        long long exponent = (long long)pow(2, p-1) - 1;
        long long term2 = power(baseValue, exponent);

        return (term1*term2)%mod;
    }
};