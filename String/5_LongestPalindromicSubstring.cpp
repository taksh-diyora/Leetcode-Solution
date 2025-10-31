class Solution {
public:
    int findPal(string s, int left, int right){
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        if(s.empty()) return "";

        int start = 0;
        int end = 0;

        for(int i=0; i<s.size(); i++){
            int odd = findPal(s, i, i);
            int even = findPal(s, i, i+1);
            int maxV = max(odd, even);

            if(maxV > end-start){
                start = i - (maxV-1)/2;
                end = i + maxV/2;
            }
        }

        return s.substr(start, end-start+1);
    }
};