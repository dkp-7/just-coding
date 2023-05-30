// Matrix Median
// Question Link (Coding Ninjas) : https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


//  Naive Approach using extra space

#include <bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix)
{
    vector<int>ds;
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            ds.push_back(matrix[i][j]);
        }
    }
    sort(ds.begin() , ds.end());
    int mid = (m*n)/2;
    return ds[mid];
}
