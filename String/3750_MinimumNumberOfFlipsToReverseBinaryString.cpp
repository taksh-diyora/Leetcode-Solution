class Solution {
public:
    int minimumFlips(int n) {
        string s = "";
        while(n!=0){
            s+=to_string(n%2);
            n/=2;
        }

        int m=0;
        n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] != s[n-i-1]) m++;
        }
        return m;
    }
};