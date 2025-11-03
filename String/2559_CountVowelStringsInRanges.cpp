class Solution {
public:
    bool isValid(char c){
        return string("aeiou").find(c) != string::npos;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n+1, 0);

        for(int i=0; i<n; i++){
            int add = (isValid(words[i][0]) && isValid(words[i][words[i].size()-1]))?1:0;
            prefix[i+1] = prefix[i]+add;
        }

        vector<int> res;

        for(auto& q: queries){
            int l = q[0], r = q[1];
            res.push_back(prefix[r+1]-prefix[l]);
        }

        return res;
    }
};