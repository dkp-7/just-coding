//  Leetcode :   51. N-Queens


class Solution {
public:

    bool isPossible(vector<string> &mat, int n, int row, int col){

        int row1 = row;
        int col1 = col;
        //checking for column above
        while(row1 >=0){
            if(mat[row1][col1] == 'Q') return false;
            row1--;
        }

        row1 = row;
        col1 = col;
        //checking for left diagonal
        while(row1 >= 0   &&   col1 >= 0){
            if(mat[row1][col1] == 'Q') return false;
            row1--;
            col1--;
        }
         
        row1 = row;
        col1 = col;
        //checking for right diagonal
        while(row1 >= 0   &&   col1 < n){
            if(mat[row1][col1] == 'Q') return false;
            row1--;
            col1++;
        }
        return true;
    }
    
    void helper(vector<string> &mat, int n, int row, vector<vector<string>> &ans){

        if(row == n){
            ans.push_back(mat);
            return;
        }
        for(int col=0; col<n; col++){

            if(isPossible(mat , n , row , col)){
                mat[row][col] = 'Q';
                helper(mat , n , row+1 , ans);
                mat[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        string s(n, '.');
        vector<string> mat;
        for(int i=0; i<n; i++){
            mat.push_back(s);
        }
        vector<vector<string>> ans;
        int row = 0;
        helper(mat , n , row , ans);
        return ans;
    }
};
