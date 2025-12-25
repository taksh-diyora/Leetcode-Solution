class Solution {
public:
    string newStr(string str, int val){
        if(val == 1) return str;

        return str+newStr(str, val-1);
    }
    string decodeString(string s) {
        stack<int> ints;
        stack<string> strs;
        int k = 0;
        for(char c: s){
            if(isdigit(c)){
                k = k*10 + (c-'0');
            }else if(c == '['){
                ints.push(k);
                k=0;
                strs.push(string(1, c));
            }else if(isalpha(c)){
                strs.push(string(1, c));
            }else{
                string temp = "";
                while(strs.top()!="["){
                    temp+=strs.top();
                    strs.pop();
                }
                strs.pop();
                int val = ints.top();
                ints.pop();

                strs.push(newStr(temp, val));
            }
        }

        string res = "";
        while(!strs.empty()){
            res+=strs.top();
            strs.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};