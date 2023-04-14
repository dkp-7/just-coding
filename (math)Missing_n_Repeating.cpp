#include <iostream>
#include <vector>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> arr , int n){
    
    
    pair<int,int> ans;
    long long int M,R;
    
    long long int sum = (n*(n+1))/2;
    long long int mul = (n*(n+1)*((2*n)+1)/6);
    
    long long int S1 = sum , M1 = mul;
    for(int x=0; x<n; x++){
        S1 = S1 - arr[x] ;
        M1 = M1 - (arr[x]*arr[x]);
    }
    
    /* we know that S1 = M-R   -----  1 
    
       M1 = M*M - R*R
       M1 = (M-R)(M+R)     -------   2
       M1 = S1(M+R)
       so,    M1/S1 = M+R    ---------  3
       
       Adding 1 and 3   as linear equations
       
       2M = M1/S1 + S1
       2M = (M1 + S1*S1)/S1
       
       M = (M1 + S1*S1)/(2*S1)   ------  4   (Finding "missing no. (M) formula")
       
       Using 1 and 3
       
       R = M - S1     --------  5      (Finding "repeating no. R formula")
       
    */
    
    // Using equations 4 & 5   SINCE WE GOT THE VALUE OF S1 & M1
    
    
    M = (M1 + S1*S1)/(2*S1);
    R = M - S1 ;
    
    ans.first = M;
    ans.second = R;
    
    return ans;
}

int main()
{
    vector<int> arr = {5,4,2,4,1};
    int n = 5;
    pair<int,int> ans = missingAndRepeating(arr , n);
    cout<<"Missing No. -> "<<ans.first<<endl<<"Repeating No. ->  "<<ans.second;
    return 0;
}
