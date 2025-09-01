class Solution {
    public:
        bool isPalindrome(string s) {
            string x = "";
            for(int i=0; i<s.size(); i++){
                if(isalnum(s[i])){
                    x+=tolower(s[i]);
                }
            }
    
            for(int i=0; i<x.size()/2; i++){
                if(x[i]!=x[x.size()-1-i]){
                    return false;
                }
            }
            return true;
        }
    };