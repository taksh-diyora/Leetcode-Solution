class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> high;
        vector<int> low;
        vector<int> equal;
        for(int i: nums){
            if(i>pivot) high.push_back(i);
            else if(i<pivot) low.push_back(i);
            else equal.push_back(i);
        }
        vector<int> n;
        n.insert(n.end(), low.begin(), low.end());
        n.insert(n.end(), equal.begin(), equal.end());
        n.insert(n.end(), high.begin(), high.end());

        return n;
    }
};