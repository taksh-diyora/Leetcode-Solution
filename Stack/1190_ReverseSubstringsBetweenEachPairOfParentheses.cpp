class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                stk.push(i);
            }else if(s[i] == ')'){
                reverse(s.begin() + stk.top(), s.begin() + i);
                stk.pop();
            }
        }

        string str = "";
        for(char c: s){
            if(c == '(' || c == ')') continue;
            str+=c;
        }

        return str;
    }
};