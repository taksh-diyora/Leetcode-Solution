class Solution {
public:
    string removeStars(string s) {
        vector<char> vec;

        for(char c: s){
            if(c == '*') vec.pop_back();
            else vec.push_back(c);
        }

        string str(vec.begin(), vec.end());

        return str;
    }
};