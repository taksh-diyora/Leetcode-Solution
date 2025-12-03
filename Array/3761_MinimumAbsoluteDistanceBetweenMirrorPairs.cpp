class Solution {
public:
    int rev(int n){
        int rev = 0;
        while(n!=0){
            rev = rev*10 + n%10;
            n/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int minD = INT_MAX;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int current = nums[i];
            int reverse_val = rev(nums[i]);
            if(mp.count(current)){
                minD = min(minD, i-mp[current]);
            }
            mp[reverse_val] = i;
        }
        if(minD == INT_MAX) return -1;
        return minD;
    }
};