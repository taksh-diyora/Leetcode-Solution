class Solution {
public:
    int count_palindrome(string s, int left, int right){
        int count = 0;
        while(left>=0 && right<s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int res = 0;
        for(int i=0; i<s.size(); i++){
            res+= count_palindrome(s, i, i);
            res+= count_palindrome(s, i, i + 1);
        }
        return res;
    }
};