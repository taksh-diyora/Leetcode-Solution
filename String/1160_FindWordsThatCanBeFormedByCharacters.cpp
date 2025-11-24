class Solution {
public:
    bool checkForm(string s, unordered_map<char, int> ch){
        for(char c: s){
            if(!ch[c]) return false;
            ch[c]--;
        }

        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        int count = 0;
        unordered_map<char, int> ch;
        for(char c: chars){
            ch[c]++;
        }

        for(string s: words){
            if(checkForm(s, ch)){
                count+= s.size();
            }
        }

        return count;
    }
};