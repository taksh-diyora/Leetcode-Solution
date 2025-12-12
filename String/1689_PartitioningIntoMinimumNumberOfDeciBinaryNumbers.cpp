class Solution {
public:
    int minPartitions(string n) {
        int maxV = 0;
        for(char c: n){
            maxV = max(maxV, c - '0');
        }
        return maxV;
    }
};