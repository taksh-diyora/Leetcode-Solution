class Solution {
public:
    bool isPossible(vector<vector<int>>& visited, vector<vector<int>>& grid, int mid, int r, int c){
        int n = grid.size();
        if(r == n-1 && c == n-1) return true;
        visited[r][c] = 1;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int ans = false;

        for(int i=0; i<4; i++){
            int row = r + dr[i];
            int col = c + dc[i];
            if(row >= 0 && row < n && col >=0 && col < n && visited[row][col] == 0){
                if(grid[row][col] <= mid){
                    ans = ans||isPossible(visited, grid, mid, row, col);
                }
            }
        }

        return ans;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int l = grid[0][0];
        int r = 0;
        for(int i=0; i<n; i++){
            r = max(r, *max_element(grid[i].begin(), grid[i].end()));
        }
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            vector<vector<int>> visited(n, vector<int>(n, 0));
            visited[0][0] = 1;
            if(isPossible(visited, grid, mid, 0, 0)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};