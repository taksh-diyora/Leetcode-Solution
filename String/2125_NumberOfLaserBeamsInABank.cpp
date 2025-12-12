class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        vector<int> vals;
        for(int i=0; i<bank.size(); i++){
            int ct = 0;
            for(char c: bank[i]){
                if(c == '1') ct++;
            }
            if(ct!=0) vals.push_back(ct);
        }
        if(vals.size()<2) return 0;
        for(int i=0; i<vals.size()-1; i++){
            count = count + vals[i]*vals[i+1];
        }
        return count;
    }
};