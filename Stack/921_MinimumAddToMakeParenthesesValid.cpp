class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;

        stack<char> stk;

        for(char c: s){
            if(c == '('){
                stk.push(c);
            }else{
                if(stk.empty()) count++;
                else{
                    stk.pop();
                }
            }
        }
        while(!stk.empty()){
            stk.pop();
            count++;
        }

        return count;
    }
};