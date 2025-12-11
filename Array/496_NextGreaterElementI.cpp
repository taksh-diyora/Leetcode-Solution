class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;

        for(int i=0; i<nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        vector<int> res(nums2.size(), -1);
        for(int i=0; i<nums2.size(); i++){
            for(int j=i+1; j<nums2.size(); j++){
                if(nums2[i] < nums2[j]){
                    res[i] = nums2[j];
                    break;
                }
            }
        }

        for(int i=0; i<nums1.size(); i++){
            nums1[i] = res[mp[nums1[i]]];
        }

        return nums1;
    }
};