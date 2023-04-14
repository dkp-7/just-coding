//search in 2d matrix which is sorted both row & column wise          (Leetcode Question 240)




bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        /*
        -> Take a reference element (which will be from 1st row & last column)
        -> Now, compare that refernce element with target
            -> If target is smaller, then change reference element index to one step left of its original position in matrix (i.e., j-- (column no. decreases))
            -> If target is bigger, then change reference element position to one step downward to its original position in matrix (i.e., i++ (row no. increases))
        */

        int m = matrix.size();
        int n = matrix[0].size();

        bool ans= false;
        int i = 0, j=n-1;

        while( (i<m)  &&  (j>=0) ){

            if(target == matrix[i][j]){
                ans = true;
                return ans;
            }
            else if(target > matrix[i][j]){
                i++;
            }
            else if(target < matrix[i][j]){
                j--;
            }
        }
        return ans;
}
