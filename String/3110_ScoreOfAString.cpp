class Solution {
public:
    int scoreOfString(string s) {
        int value = 0;
        for(int i=0; i<s.size()-1; i++){
            value+=abs(s[i]-s[i+1]);
        }
        return value;
    }
};