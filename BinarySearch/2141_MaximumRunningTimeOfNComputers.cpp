class Solution {
public:
    bool isPossible(vector<int>& batteries, int n, long long time){
        long long dur = 0;
        for(int i: batteries){
            dur+=min((long long)i, time);
            if(dur >= time*n) return true;
        }

        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0;
        long long r = 0;
        for(int b: batteries) r+=b;
        long long ans = -1;

        while(l<=r){
            long long mid = l + (r-l)/2;

            if(isPossible(batteries, n, mid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
};