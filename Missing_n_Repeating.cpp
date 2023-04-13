#include <bits/stdc++.h>
#include <iostream>

using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	pair<int,int> ans;
	vector<int> temp(n+1,0);
	int R, M;
	for(int i=0; i<=n; i++){
		temp[arr[i]] = temp[arr[i]] + 1;
		
	}

	for(int i=1; i<=n; i++){
		if(temp[i] > 1){
			R = i;
		}
		if(temp[i] == 0){
			M = i;
		}
	}
	
	ans.first = M;
	ans.second = R;
	cout<<M<<"  "<<R;
	return ans;
	
}

int main()
{
    vector<int> arr = {5,4,2,4,1};
    int n = 5;
    pair<int,int> ans = missingAndRepeating(arr , n);
    cout<<ans.first<<"  "<<ans.second;
    return 0;
}
