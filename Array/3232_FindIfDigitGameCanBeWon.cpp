class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int oned = 0;
        int twod = 0;

        for(int i: nums){
            if(i<10) oned+=i;
            else twod+=i;
        }

        return twod!=oned;
    }
};