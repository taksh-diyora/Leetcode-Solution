class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n + 1, 0);

        for (int num : nums) {
            counts[num]++;
        }

        int duplicate = -1;
        int missing = -1;

        for (int i = 1; i <= n; ++i) {
            if (counts[i] == 2) {
                duplicate = i;
            } else if (counts[i] == 0) {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};