class Solution {
public:
    int n;
    bool isPallindrome(int l, int r, string s){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void solve(vector<vector<string>> &ans, vector<string> &temp, string &s, int idx){
        if(idx == n){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < s.length(); i++){
            if(isPallindrome(idx, i, s)){
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(ans, temp, s, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans, temp, s, 0);
        return ans;
    }
};