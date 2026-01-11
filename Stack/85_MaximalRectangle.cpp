class Solution {
public:
    int LRA(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n)?0:heights[i];

            while (!st.empty() && currHeight<heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty()? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix[0].size();
        vector<int> curr(n, 0);

        for(auto& hist: matrix){
            for(int i=0; i<n; i++){
                if(hist[i] == '1'){
                    curr[i]++;
                }else curr[i] = 0;
            }
            ans = max(ans, LRA(curr));
        }

        return ans;
    }
};