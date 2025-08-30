class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]] = i;
        }
        int st=0;
        int e=0;
        vector<int> res;
        for(int i=0; i<s.size(); i++){
            e = max(e, m[s[i]]);
            if(i==e){
                res.push_back(e-st+1);
                st = i+1;
            }
        }
        return res;
    }
};