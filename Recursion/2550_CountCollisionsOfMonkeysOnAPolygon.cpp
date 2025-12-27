class Solution {
public:
    int mod = 1e9+7;
    long long solve(int n){
        long long res = 1;
        long long base = 2;
        
        while(n > 0){
            if(n%2==1) res = (res*base)%mod;
            n/=2;
            base = (base*base)%mod;
        }

        return res;
    }
    int monkeyMove(int n) {
        long long total = solve(n);

        return (total-2+mod)%mod;
    }
};