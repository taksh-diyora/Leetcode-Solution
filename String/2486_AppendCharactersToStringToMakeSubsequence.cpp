class Solution {
public:
    int appendCharacters(string s, string t) {
        int a = 0;
        int m = s.size();
        int n = t.size();
        for(int i=0; i<m; i++){
            if(a<n && s[i] == t[a]) a++;
        }
        return n - a;
    }
};