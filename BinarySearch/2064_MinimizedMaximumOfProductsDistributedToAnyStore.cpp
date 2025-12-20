class Solution {
public:
    bool isPossible(vector<int>& quantities, int mid, int n){
        int stores = 0;
        for(int i: quantities){
            stores+=i/mid;
            if(i%mid>0) stores++;
        }

        return stores<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = INT_MIN;
        for(int i: quantities){
            r = max(i, r);
        }

        int ans = r;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(isPossible(quantities, mid, n)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};