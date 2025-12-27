class Solution {
public:
    vector<int> fact, vals;
    string solve(int n, int k){
        if(n == 0) return "";

        int blockSize = fact[n-1];
        int index = k/blockSize;

        string ch = to_string(vals[index]);

        vals.erase(vals.begin()+index);
        k = k%blockSize;
        
        return ch + solve(n-1, k);
    }
    string getPermutation(int n, int k) {
        int f = 1;
        fact.push_back(1);
        for(int i=1; i<=9; i++){
            f *= i;
            fact.push_back(f);
        }

        for(int i=1; i<=n; i++){
            vals.push_back(i);
        }
        
        return solve(n, k-1);
    }
};