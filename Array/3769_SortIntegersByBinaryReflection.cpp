int Reflect(int x) {
    int ret=0;
    while(x) {
        ret = ret*2+(x%2);
        x/=2;
    }
    return ret;
}
class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),[&](int x,int y) {
            return make_pair(Reflect(x), x) < make_pair(Reflect(y), y);
        });
        return nums;
        
    }
};