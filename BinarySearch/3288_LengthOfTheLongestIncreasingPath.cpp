class Solution {
public:
    int LIS(vector<pair<int, int>>& nums){
        vector<int> tails;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i].second;
            auto it = lower_bound(tails.begin(), tails.end(), num);

            if(it == tails.end()){
                tails.push_back(num);
            }else{
                *it = num;
            }
        }

        return tails.size();
    }
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        auto cmp = [](pair<int,int> &i , pair<int,int>& j){
            if(i.first < j.first)return true;
            else if(i.first == j.first){
                return i.second > j.second;
            }
            else return false;
        };

        int n = coordinates.size();
        vector<pair<int,int>> left, right;

        for(int i = 0 ; i<n ; i++){
            if(coordinates[i][0] < coordinates[k][0] && coordinates[i][1] < coordinates[k][1]){
                left.push_back({coordinates[i][0] , coordinates[i][1]});
            }
            if(coordinates[i][0] > coordinates[k][0] && coordinates[i][1] > coordinates[k][1]){
                right.push_back({coordinates[i][0] , coordinates[i][1]});
            }
        }

        sort(left.begin(), left.end(), cmp);
        sort(right.begin(), right.end(), cmp);

        int l = LIS(left);
        int r = LIS(right);

        return l+1+r;
    }
};