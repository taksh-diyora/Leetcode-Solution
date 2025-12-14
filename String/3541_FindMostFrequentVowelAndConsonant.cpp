class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        int maxV = 0;
        int maxC = 0;
        string str = "aeiou";
        for(char c: s){
            mp[c]++;
            if(str.contains(c)){
                maxV = max(maxV, mp[c]);
            }else{
                maxC = max(maxC, mp[c]);
            }
        }

        return maxV+maxC;
    }
};