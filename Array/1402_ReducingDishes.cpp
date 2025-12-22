class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int total = 0;
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        for(int i=0; i<n; i++){
            int vals = 0;
            for(int j=i; j<n; j++){
                vals+=satisfaction[j]*(j-i+1);
            }

            total = max(total, vals);
        }

        if(total < 0) return 0;
        return total;
    }
};