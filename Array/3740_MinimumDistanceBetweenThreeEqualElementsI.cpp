class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int minV = INT_MAX;

        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                if(nums[i] == nums[j]){
                    for(int k=j+1; k<n; k++){
                        if(nums[i] == nums[k]){
                            minV = min(minV, abs(i-j)+abs(j-k)+abs(i-k));
                        }
                    }
                }
            }
        }

        if(minV == INT_MAX) return -1;
        return minV;
    }
};