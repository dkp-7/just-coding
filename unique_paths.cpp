// Leetcode 62. Unique Paths    (From top left (0,0)  to  bottom right  (m-1,n-1)

// Optimal way to solve this is to use dynamic programming in the recursive approach

class Solution {
public:
    int helper(int m, int n, int i, int j, vector<vector<int>> &dp){
        
        if(i==m-1  &&  j==n-1){
            return 1;
        }
        
        if(i==m  ||  j==n){
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = helper(m, n, i+1, j, dp);
        int right = helper(m, n, i, j+1, dp);
        
        dp[i][j] = down + right;
        
        return dp[i][j];
        
    }
    
    int uniquePaths(int m, int n) {
        
        int i=0, j=0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        int ans = helper(m, n, i, j, dp);
        
        return ans;
    }
};




/*

// these are recursive approach, in this TC is exponential and time limit exceeds when we run the code because we go through all the possibilities

void helper(int m, int n, int i, int j, int &cnt){
        
        if(i==m-1  &&  j==n-1){
            cnt++;    (From top left (0,0)  to  bottom right  (m-1,n-1)
            
            // Best wy to solve this is to use dynamic programming in the recursive approach
            return;
        }
        if(i==m  ||  j==n){
            return;
        }
        helper(m, n, i+1, j, cnt);
        helper(m, n, i, j+1, cnt);
        return;
    }
    
    int uniquePaths(int m, int n) {
        
        int i=0, j=0;
        int cnt = 0;
        helper(m, n, i, j, cnt); 
        return cnt;
    }


///////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int helper(int m, int n, int i, int j){
        
        if(i==m-1  &&  j==n-1){
            return 1;
        }
        
        if(i==m  ||  j==n){
            return 0;
        }
        
        int down = helper(m, n, i+1, j);
        int right = helper(m, n, i, j+1);
        
        int ans = down+right;
        
        return ans;
        
    }
    
    int uniquePaths(int m, int n) {
        
        int i=0, j=0;
        
        int ans = helper(m, n, i, j);
        
        return ans;
    }
};

*/
