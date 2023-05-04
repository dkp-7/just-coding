// Question :   0/1 Knapsack problem


#include <vector>
#include <iostream>

using namespace std;

int knapsack01(vector<int> &v,vector<int> &w, int N, int W) {
    vector<vector<int>> dp(N+1, vector<int>(W+1,0)); // Defining DP 
    

    /* If there is no space left that is W reaches 0 then DP[i][0] 
    for every i will be 0.*/
//    for(int i=0;i<N+1;i++) dp[i][0] = 0;

    /* If there are no items left that is N reaches 0 then DP[0][i] 
    for every i will be 0.*/ 
//    for(int i=0;i<W+1;i++) dp[0][i] = 0;

    for(int i=1;i<N+1;i++){
        for(int j=1;j<W+1;j++){       //this represents weight
            if(w[i-1] <= j){
                /* Taking max of both the cases i.e to take that 
                item or to ignore it.*/
                dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]); 
            }
            else{
                /* If the weight of current element is greater 
                than the space left in the bag we'll ignore it.*/
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[i].size(); j++){
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
    }
    
    /* returning answer for W space and N items */
    return dp[N][W]; }

int main()
{
    vector<int> p = {1,2,5,6};
    vector<int> w = {2,3,4,5};
    int n = 4;    //total no. of items
    int m = 8;    //maximum weight a bag can hold
    
    int max_profit = knapsack01(p,w,n,m);
    cout<<max_profit;
    return 0;
}
