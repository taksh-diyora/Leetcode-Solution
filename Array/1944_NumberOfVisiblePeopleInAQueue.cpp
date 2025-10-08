class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();

        stack<int> stk;
        vector<int>ans(n, -1);

        for(int i=n-1; i>=0; i--){
            int count = 0;
            while(!stk.empty() && heights[stk.top()]<heights[i]){
                stk.pop();
                count++;
            }
            if(!stk.empty()) count++;
            ans[i]=count;
            stk.push(i);
        }
        return ans;
    }
};