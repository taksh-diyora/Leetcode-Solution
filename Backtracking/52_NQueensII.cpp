class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        int r = row;
        int c = col;

        while(r>=0 && c>=0){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row;
        c = col;

        while(c>=0){
            if(board[r][c] == 'Q') return false;
            c--;
        }

        c = col;
        while(r<n && c>=0){
            if(board[r][c] == 'Q') return false;
            c--;
            r++;
        }

        return true;
    }
    void solve(int col, vector<string> &board, int &ans, int n){
        if(col == n){
            ans++;
            return;
        }

        for(int row = 0; row< n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n);
        string s(n, '.');

        for(int i=0; i<n; i++){
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }
};