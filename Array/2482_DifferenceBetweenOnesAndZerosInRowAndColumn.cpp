class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]) rows[i]++;
                else rows[i]--;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[j][i]) cols[i]++;
                else cols[i]--;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = rows[i]+cols[j];
            }
        }

        return grid;
    }
};