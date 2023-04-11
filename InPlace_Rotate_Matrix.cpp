void rotate(vector<vector<int>>& matrix) {
        
        //Since each column is in reverse form as a row in rotated matrix, therfore
  
        int n= matrix.size();
        //transpose the matrix
        for(int i=0; i<n-1; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        //reversing each row of matrix
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        } 
}


/*
OR

void rotate(vector<vector<int>>& matrix) {
        
        int n= matrix.size();

        //reversing evEry row
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
        //swapping i(th row) with (n-1)-i column, but leaving last (row no.)elements of the row
        for(int i=0; i<n-1; i++){
            for(int j=0; j<(n-1)-i; j++){
                swap( matrix[i][j] , matrix[(n-1)-j][(n-1)-i] );
            }
        }
}

*/
