class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxL = 0;
        int maxR = 0;
        int water = 0;
        while(left<right){
            maxL = max(maxL, height[left]);
            maxR = max(maxR, height[right]);
            if(maxL<=maxR){
                water+= maxL - height[left];
                left++;
            }else{
                water+= maxR-height[right];
                right--;
            }
        }
        return water;
    }
};