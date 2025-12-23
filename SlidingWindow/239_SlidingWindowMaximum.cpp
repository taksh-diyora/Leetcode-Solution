class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        vector<int> vals;
        for(int i=0; i<k; i++){
            mp[nums[i]]++;
        }
        vals.push_back(mp.rbegin()->first);
        for(int i=k; i<n; i++){
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0){
                mp.erase(nums[i-k]);
            }
            mp[nums[i]]++;
            vals.push_back(mp.rbegin()->first);
        }

        return vals;
    }
};