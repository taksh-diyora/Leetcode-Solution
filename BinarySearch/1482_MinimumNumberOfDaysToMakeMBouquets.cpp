class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int day){
        int adjBloom = 0;
        int bouquets = 0;
        for(int i: bloomDay){
            if(i<=day){
                adjBloom++;
            }else{
                bouquets+=adjBloom/k;
                adjBloom = 0;
            }
        }
        bouquets+=adjBloom/k;
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int l = INT_MAX;
        int r = INT_MIN;

        for(int i: bloomDay){
            l = min(l, i);
            r = max(r, i);
        }

        int minDay = -1;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(isPossible(bloomDay, m, k, mid)){
                minDay = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return minDay;
    }
};