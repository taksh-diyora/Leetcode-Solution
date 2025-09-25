class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int a = 0;
        int v = 0;
        int row = matrix.size();
        int column = matrix[0].size();
        vector<int> ans(row*column);
        while(v < row*column){
            for(int i = a; i < column - a; i++){
                if(v < row*column) ans[v++] = matrix[a][i];
            }

            for(int i = a+1; i < row - a; i++){
                if(v < row*column) ans[v++] = matrix[i][column-1-a];
            }

            if(row-1-a > a){
                for(int i = column-a-2; i >= a; i--){
                    if(v < row*column) ans[v++] = matrix[row-1-a][i];
                }
            }

            if(column-1-a > a){
                for(int i = row-a-2; i > a; i--){
                    if(v < row*column) ans[v++] = matrix[i][a];
                }
            }

            a++;
        }
        return ans;
    }
};
