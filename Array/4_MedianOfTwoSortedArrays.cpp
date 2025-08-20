class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size;
        double sum = 0;
        for(int i=0; i<nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        size = nums1.size();
        if(size%2==0){
            sum = (nums1[size/2]+nums1[size/2-1]);
        }else{
            sum = nums1[size/2]*2;
        }
        return sum/2.0;
    }
};