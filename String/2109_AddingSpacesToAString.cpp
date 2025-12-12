class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int n = spaces.size();
        int a = 0;
        for(int i=0; i<s.size(); i++){
            if(a<n && spaces[a] == i){
                res+=" ";
                a++;
            }
            res+=s[i];
        }
        return res;
    }
};