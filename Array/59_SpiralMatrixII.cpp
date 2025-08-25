class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int a = 1;
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        while(top<=bottom && left<=right){
            for(int i=left; i<=right; i++){
                mat[top][i] = a++;
            }
            top++;

            for(int i=top; i<=bottom; i++){
                mat[i][right] = a++;
            }
            right--;

            for(int i=right; i>=left; i--){
                mat[bottom][i] = a++;
            }
            bottom--;

            for(int i=bottom; i>=top; i--){
                mat[i][left] = a++;
            }
            left++;
        }
        return mat;
    }
};