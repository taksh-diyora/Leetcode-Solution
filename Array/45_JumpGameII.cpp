class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int maxReach = 0;
        int currentReach = 0;
        int n = nums.size();
        int jumps = 0;
        for(int i=0; i<n; i++){
            maxReach = max(maxReach, i+nums[i]);

            if(i==currentReach){
                jumps++;
                currentReach = maxReach;
                
                if(currentReach >= n-1) break;
            }
        }
        return jumps;
    }
};