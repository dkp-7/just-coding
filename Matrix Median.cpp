// Matrix Median
// Question Link (Coding Ninjas) : https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


// Optimaal Approach using Binary Search

int lessThanOrEqual(vector<int> mat , int limit){
    int l = 0;
    int h = mat.size()-1;                //here -1 at the end is very important to pass all given the test case (the search space should be from index 0 to last index)
    
    while(l <= h){
        int md = (l+h)/2;
        if(mat[md] <= limit){
            l = md+1;
        }
        else h=md-1;
    }
    return l;        //this line will return the value as (index+1), which is the count of elements less than or equal to limit value 
}


int getMedian(vector<vector<int>> &matrix)
{
    int low = 1;
    int high = 1e9;
    int m = matrix.size();
    int n = matrix[0].size();

    while(low <= high){
        int mid = (low+high)/2;
        int cnt = 0;
        for(int i=0; i<m; i++){
            cnt += lessThanOrEqual(matrix[i] , mid);
        }
        if(cnt <= (m*n)/2){
            low = mid+1;
        }
        else high=mid-1;
        
    }
    return low;         // this line will return the value one greater than ((m8n)/2) i.e one more than the index value of middle element from total element of matrix whose indexing starts from 0



---------------------------------------------------------------------------------------------------------------------

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
