class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        int mid = -1;
        int count = 0;

        while(l<r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                int k = r;
                while(s[k]!=s[l]){
                    k--;
                }
                if(k == l){
                    mid = l;
                    l++;
                }else{
                    while(k!=r){
                        swap(s[k], s[k+1]);
                        k++;
                        count++;
                    }
                    l++,
                    r--;
                }
            }
        }

        if(mid!=-1){
            return count + s.size()/2 - mid;
        }

        return count;
    }
};