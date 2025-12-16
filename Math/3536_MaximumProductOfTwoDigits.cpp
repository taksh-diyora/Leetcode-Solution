class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);

        int mval = 0;

        for(int i=0; i<s.size(); i++){
            if(s[mval] < s[i]){
                mval = i;
            }
        }
        int smval = 0;
        if(mval == 0){
            smval = 1;
        }
        for(int i=0; i<s.size(); i++){
            if(mval == i) continue;
            if(s[smval] < s[i]){
                smval = i;
            }
        }

        return (s[mval] - '0')*(s[smval] - '0');
    }
};