// Question (Coding Ninjas) :  Merge K Sorted Arrays
// Link :  https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0


#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int> pq;
    int cnt=0;
    for(int i=0; i<kArrays.size(); i++){
        for(int j=0; j < kArrays[i].size(); j++){
            pq.push(kArrays[i][j]);
            cnt++;
        }
    }
    vector<int> ans(cnt,0);
    for(int i=cnt-1; i>=0; i--){
        ans[i] = pq.top();
        pq.pop();
    }
    return ans;
}
