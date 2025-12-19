class Solution {
public:
    bool isPossible(vector<int>& candies, long long mid, long long k){
        long long partitions = 0;
        for(int i: candies){
            if(i>=mid) partitions+=i/mid;
            if(partitions>=k) break;
        }
        return k<=partitions;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long l = 1;
        long long r = 0;
        for(int i: candies){
            r += i;
        }
        long long maxCandies = 0;

        if(r < k) return 0;

        r = r/k;

        while(l<=r){
            long long mid = l + (r-l)/2;

            if(isPossible(candies, mid, k)){
                l = mid+1;
                maxCandies = mid;
            }else{
                r = mid-1;
            }
        }

        return static_cast<int>(maxCandies);
    }
};