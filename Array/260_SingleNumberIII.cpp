class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorV = 0;
        for(int num: nums){
            xorV ^= num;
        }
        int diff=-xorV&xorV;

        int num1 = 0;
        int num2 = 0;
        for(int num: nums){
            if((num & diff)!=0) num1 = num1^num;
            else num2 = num2^num;
        }

        return {num1, num2};
    }
};