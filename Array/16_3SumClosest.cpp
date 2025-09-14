class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int j, k;
        sort(nums.begin(), nums.end());
        int closest = 50000;
        for(int i=0; i<n; i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            j=i+1;
            k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(target-closest)>abs(target-sum)){
                    closest=sum;
                }
                if(target==sum) return target;
                else if(target>sum){
                    j++;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }else{
                    k--;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return closest;
    }
};