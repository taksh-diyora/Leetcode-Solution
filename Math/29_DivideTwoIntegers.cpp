class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool negative = (dividend<0) ^ (divisor<0);
        long long a = llabs(dividend);
        long long b = llabs(divisor);
        long long quotient = 0;

        while(a>=b){
            long long temp = b;
            long long multiple = 1;

            while(a >= temp+temp){
                temp+=temp;
                multiple+=multiple;
            }

            a-=temp;
            quotient += multiple;
        }

        if(negative) quotient = -quotient;

        if(quotient>INT_MAX) return INT_MAX;
        if(quotient<INT_MIN) return INT_MIN;

        return quotient;
    }
};