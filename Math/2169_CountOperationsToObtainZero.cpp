class Solution {
public:
    int countOperations(int num1, int num2) {
        return (!num1 || !num2)?0: num1/num2 + countOperations(num2, num1%num2);
    }
};