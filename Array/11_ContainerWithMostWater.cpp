class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int n = height.size()-1;
        int right = n;
        int m = 0;

        while(left<right){
            m = max(m, (n)*min(height[left], height[right]));
            if(height[right]>height[left]){
                left++;
                n--;
            }else{
                right--;
                n--;
            }
        }
        return m;
    }
};