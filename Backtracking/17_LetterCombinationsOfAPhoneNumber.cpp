class Solution {
public:
    void backtrack(unordered_map<char, string>& m, int idx, string digits, vector<string>& res, string currString){
        if(currString.size() == digits.size()){
            res.push_back(currString);
            return;
        }

        for(char c: m[digits[idx]]){
            backtrack(m, idx+1, digits, res, currString+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack(m, 0, digits, res, "");
        return res;
    }
};