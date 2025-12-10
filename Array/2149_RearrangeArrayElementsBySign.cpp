class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        int pos = 0;
        int neg = 1;

        for(int i: nums){
            if(i>0){
                res[pos] = i;
                pos+=2;
            }else{
                res[neg] = i;
                neg+=2;
            }
        }

        return res;
    }
};