// Question (Coding Ninjas):  K Max Sum Combinations
//Link :  https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	priority_queue<int> pq;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			pq.push(a[i]+b[j]);
		}
	}
	
	vector<int> ans;
	for(int i=0; i<k; i++){
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}


-----------------------------------------------------------------------------------------------------


#include <bits/stdc++.h> 

void check(vector<int> &ans, int sum){
	int minimum = ans[0];
	int ind=0;
	for(int i=1; i<ans.size(); i++){
		if(minimum > ans[i]){
			minimum = ans[i];
			ind = i;
		}
	}
	if(minimum < sum){
		ans[ind] = sum;
	}
}

bool compare(int a , int b){
	return a > b;
}

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){

	vector<int> ans(k,INT_MIN);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int sum = a[i]+b[j];
			check(ans, sum);
		}
	}
	sort(ans.begin() , ans.end() , compare);
	return ans;
}
