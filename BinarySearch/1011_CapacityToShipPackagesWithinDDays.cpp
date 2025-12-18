class Solution {
public:
    bool isPossible(int capacity, int days, vector<int>& weights){
        int d = 1;
        int weg = 0;
        for(int i: weights){
            if(weg + i > capacity){
                d++;
                weg = i;
            }else{
                weg+=i;
            }
        }
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int r = 0;
        for(int i: weights){
            l = max(l, i);
            r+=i;
        }
        int result = r;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(isPossible(mid, days, weights)){
                result = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return result;

    }
};