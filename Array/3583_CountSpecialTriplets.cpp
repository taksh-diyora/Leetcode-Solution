class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> l;
        unordered_map<int, int> mp;
        const int m = 1e9 + 7;
        for(int i: nums){
            mp[i]++;
        }

        long long count = 0;

        for(int i: nums){
            l[i]++;
            long long lv, rv;
            if(i == 0){
                lv = l[i*2] - 1;
                rv = mp[i*2] - lv -1;
            }else{
                lv = l[i*2];
                rv = mp[i*2] - lv;
            }
            long long product = (lv%m*(rv%m))%m;
            count = (count%m+product)%m;
        }

        return static_cast<int>(count);
    }
};