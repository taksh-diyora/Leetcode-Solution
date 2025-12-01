class Solution {
public:
    int maxDistinct(string s) {
        int count = 0;
        unordered_map<char, int> map;

        for(char c: s){
            if(!map[c]){
                count++;
                map[c]++;
            }
        }

        return count;
    }
};