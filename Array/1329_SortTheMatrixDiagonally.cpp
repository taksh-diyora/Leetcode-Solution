class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> vals(m+n-1);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int idx = m-1+j-i;
                vals[idx].push_back(mat[i][j]);
            }
        }

        for(int i=0; i<m+n-1; i++){
            sort(vals[i].begin(), vals[i].end());
        }

        vector<int> index(m+n-1, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int id = m-1+j-i;
                mat[i][j] = vals[id][index[id]++];
            }
        }

        return mat;
    }
};