class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char, int> mp;
        for(char c: brokenLetters){
            mp[c]=1;
        }
        stringstream ss(text);
        int count = 0;
        string word;
        while(ss >> word){
            bool flag = true;
            for(char c: word){
                if(mp[c]){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }

        return count;
    }
};