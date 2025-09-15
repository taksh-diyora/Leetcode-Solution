class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i, j, k, l;
        long long sum;
        int n=nums.size();
        for(i=0; i<n; i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(j=i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                k=j+1;
                l=n-1;
                while(k<l){
                    sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        ans.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                        while(k<l&&nums[k]==nums[k-1])k++;
                        while(k<l&&nums[l]==nums[l+1])l--;
                    }else if(sum<target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};