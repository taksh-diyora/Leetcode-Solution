class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> filtered;
        
        for (auto& r : restaurants) {
            bool satisfiesVegan = (veganFriendly == 0) || (r[2] == 1);
            
            if (satisfiesVegan && r[3] <= maxPrice && r[4] <= maxDistance) {
                filtered.push_back(r);
            }
        }

        sort(filtered.begin(), filtered.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        });

        vector<int> result;
        for (auto& r : filtered) {
            result.push_back(r[0]);
        }
        
        return result;
    }
};