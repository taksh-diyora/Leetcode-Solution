class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = piles[0];

        for(int i: piles){
            r = max(r, i);
        }

        while(l<=r){
            int mid = l + (r-l)/2;
            long long hr = 0;
            for(int i: piles){
                hr += i/mid + ((i%mid > 0)?1:0);
            }
            
            if(h < hr){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return l;
    }
};