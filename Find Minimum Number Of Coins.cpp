Question :  Find Minimum Number Of Coins

Link : https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


//optimal solution              TC : O(n)         SC : O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int amount = 70;
    vector<int> coins{1,2,5,10,20,50,100,500,1000};
    int n = coins.size();
    int cnt=0;
    for(int i=n-1; i>=0; i--){
        
        if(coins[i] <= amount){
            cnt = cnt + (amount/coins[i]);
            amount = amount % coins[i];
        }
        
        if(amount == 0) break;
    }
    
    cout<<cnt;
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h> 

int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> coins{1,2,5,10,20,50,100,500,1000};
    int n = coins.size();
    int cnt=0;
    
    int k=n-1;
    while(amount > 0){

        while(coins[k] <= amount ){
            amount = amount-coins[k];
            cnt++;
        }
        k--;
    }
    return cnt;
}
