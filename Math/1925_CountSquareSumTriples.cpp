class Solution {
public:
    int countTriples(int n) {
        if(n==1) return 0;
        int count = 0;
        for(int left = 1; left<n; left++){
            for(int right = 1; right<n; right++){
                int value = left*left + right*right;
                int rt = sqrt(value);

                if(rt*rt == value && rt<=n) count++;
            }
        }
        return count;
    }
};