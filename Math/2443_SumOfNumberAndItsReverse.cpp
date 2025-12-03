class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0) return true;
        for(int i=num/2; i<num; i++){
            int rev = 0;
            int v = i;
            while(v!=0){
                rev = rev*10+v%10;
                v/=10;
            }
            if(i+rev == num) return true;
        }
        return false;
    }
};