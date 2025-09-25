#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> sortDiagonal(vector<vector<int>>& matrix){
    int n = matrix.size();
    vector<vector<int>> sortM(n, vector<int>(n));
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = n-1;
    
}