class Solution {
public:
    int pv(int n){
        int p = 0;

        string digits = to_string(n);
        for(int i=1; i<digits.size()-1; i++){
            if(((digits[i-1])>(digits[i]) && (digits[i+1])>(digits[i])) || ((digits[i-1])<(digits[i]) && (digits[i+1])<(digits[i]))){
                p++;
            }
        }
        return p;
    }
    int totalWaviness(int num1, int num2) {
        if(num1<100 && num2<100) return 0;
        num1 = num1<=100?100:num1;
        int count = 0;
        for(int i=num1; i<=num2; i++){
            count+=pv(i);
        }
        return count;
    }
};