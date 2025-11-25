class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int value = 0;

        for(char c:s){
            if(c == 'a'){
                value++;
            }else{
                value--;
            }
        }

        return abs(value);
    }
};