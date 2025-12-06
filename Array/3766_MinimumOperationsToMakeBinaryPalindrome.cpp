class Solution {
public:
    bool isBinaryPalindrome(int x){
        string s = "";
        while(x>0){
            s+=(x&1)?'1':'0';
            x>>=1;
        }
        int l=0, r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++; r--;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans(nums.size());

        vector<int> pals;
        for(int i=1; i<=10000; i++){
            if(isBinaryPalindrome(i)) pals.push_back(i);
        }

        for(int i=0; i<nums.size(); i++){
            int x = nums[i];

            auto it = lower_bound(pals.begin(), pals.end(), x);
            int best = INT_MAX;

            if(it!=pals.end()) best = min(best, abs(*it-x));
            if(it!=pals.begin()){
                it--;
                best = min(best, abs(*it-x));
            }

            ans[i] = best;
        }
        return ans;
    }
};