class Solution {
public:
    int rev(int n){
        long long rev = 0;
        while(n!=0){
            rev = rev*10 + n%10;
            n/=10;
        }

        return static_cast<int>(rev);
    }
    int mirrorDistance(int n) {
        return abs(n - rev(n));
    }
};