class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        unordered_map<char, int> m;
        while(right<s.size()){
            m[s[right]]++;
            while(m[s[right]]>1){
                m[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};