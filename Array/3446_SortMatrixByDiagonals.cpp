class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> diags(2*n - 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int id = n - 1 + (j - i);
                diags[id].push_back(grid[i][j]);
            }
        }

        for(int id = 0; id < 2*n - 1; id++){
            if(id <= n-1)
                sort(diags[id].begin(), diags[id].end(), greater<int>());
            else
                sort(diags[id].begin(), diags[id].end());
        }

        vector<int> index(2*n - 1, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int id = n - 1 + (j - i);
                grid[i][j] = diags[id][index[id]++];
            }
        }

        return grid;
    }
};
