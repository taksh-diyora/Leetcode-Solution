class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string, int> m;
        int count = 0;
        
        vector<string> values = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        for(string s: words){
            string str = "";
            for(char c: s){
                str+=values[c-'a'];
            }
            if(m[str] == 0){
                count++;
                m[str]++;
            }
        }

        return count;
    };
};