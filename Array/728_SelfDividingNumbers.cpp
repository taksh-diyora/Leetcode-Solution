class Solution {
public:
    bool checkNum(int n){
        int temp = n;
        while(temp!=0){
            int rem = temp%10;
            if(rem == 0 || n % rem != 0) return false;
            temp/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> nums;
        for(int i=left; i<=right; i++){
            if(checkNum(i)){
                nums.push_back(i);
            }
        }
        return nums;
    }
};