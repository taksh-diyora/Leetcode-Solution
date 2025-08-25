class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size()-1;
        int n = matrix[0].size();
        while(top<=bottom){
            int mid = top + (bottom-top)/2;
            if(target>= matrix[mid][0] && target<=matrix[mid][n-1]){
                return isFound(matrix[mid], n, target);
            }
            else if(matrix[mid][0]>target){
                bottom = mid - 1;
            }else{
                top = mid + 1;
            }
        }
        return false;
    }
    bool isFound(vector<int>& arr, int n, int target){
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid] == target){
                return true;
            }else if(arr[mid]>target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }
};



/*
Another approach: 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.[0]size();
        int left = 0;
        int right = m*n -1;

        while(left<=right){
            int mid = left + (right-left)/2;
            int val = matrix[mid/n][mid%n];
            if(val==target) return true;
            else if(val>target) right = mid - 1;
            else left = mid + 1;
        }

        return false;
    }

*/