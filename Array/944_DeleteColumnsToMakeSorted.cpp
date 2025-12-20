class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size();
        int c = strs[0].size();
        int count = 0;
        for(int i = 0; i<c; i++){
            for(int j = 1; j<r; j++){
                if(strs[j][i] - strs[j-1][i] < 0){
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};