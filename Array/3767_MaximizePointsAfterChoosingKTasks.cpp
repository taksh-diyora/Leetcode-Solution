class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        vector<array<long long, 3>> diff;
        int n=technique1.size();

        for(int i=0; i<n; i++){
            long long d = (long long)technique2[i]-technique1[i];
            diff.push_back({d, technique1[i], technique2[i]});
        }
        sort(diff.begin(), diff.end());
        long long ans = 0;

        for(int i=0; i<k; i++) ans+= diff[i][1];
        for(int i=k; i<n; i++) ans+= max(diff[i][1], diff[i][2]);

        return ans;
    }
};