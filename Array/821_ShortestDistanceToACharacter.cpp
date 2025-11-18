class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> distance(s.size(), 100000);
        for(int i=0; i<s.size(); i++){
            int l = i;
            int r = i;
            while(l>=0){
                if(s[l] == c){
                    distance[i] = i-l;
                    break;
                }
                l--;
            }
            while(r<s.size()){
                if(s[r] == c){
                    distance[i] = min(distance[i], r-i);
                    break;
                }
                r++;
            }
        }
        return distance;
    }
};