class Solution {
public:
    int largestPrime(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i=2; i*i<=n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=n; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for(int i=2; i<=n; i++) if(isPrime[i]) primes.push_back(i);

        int sum = 0;
        int ans = 0;
        for(int p: primes){
            sum += p;
            if(sum>n) break;
            if(isPrime[sum]) ans = sum;
        }

        return ans;
    }
};