class Solution {
public:
    bool isPrime(long long n){
        if(n<=1) return false;
        if(n<=3) return true;
        if(n%2==0 || n%3==0) return false;
        for(long long i=5; i*i<=n; i+=6){
            if(n%i==0||n%(i+2)==0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        for(int i=1; i<=n; i++){
            int prefix = stoi(s.substr(0, i));
            if(!isPrime(prefix)) return false;
        }

        for(int i=1; i<=n; i++){
            int suffix = stoi(s.substr(n-i));
            if(!isPrime(suffix)) return false;
        }

        return true;
    }
};