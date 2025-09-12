class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for(int i: nums){
            m[i]++;
            if(m[i]>nums.size()/3) s.insert(i);
        }
        return vector<int>(s.begin(), s.end());
    }
};