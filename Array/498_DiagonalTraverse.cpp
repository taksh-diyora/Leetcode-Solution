class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return {};
        int row = mat.size();
        int column = mat[0].size();
        int m = 0;
        int n  = 0;
        vector<int> vec(row*column);
        for(int i = 0; i<row*column; i++){
            vec[i] = mat[m][n];

            /*
            mn 0 1 2 3
            
            0  1 2 3 4
            1  5 6 7 8
            2  2 3 4 5
            3  6 7 8 9

            0 0			n++
            0 1  1 0		n-- m++		m++
            2 0  1 1  0 2		m-- n++		m-- n++		n++
            0 3  1 2  2 1  3 0	n-- m++		n-- m++		n-- m++		n++
            3 1  2 2  1 3		m-- n++		m-- n++		m++
            2 3  3 2		m++ n--		n++
            3 3
            */

            if((m+n)%2==0){
                if(n == column-1) m++;
                else if(m == 0) n++;
                else m--, n++;
            }else{
                if(m == row-1) n++;
                else if(n == 0) m++;
                else n--, m++;
            }
        }
        return vec;
    }
};