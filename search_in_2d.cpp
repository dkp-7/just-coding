// Optimal Approach              (Leetcode Question 74)

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();     //row size
        int n = matrix[0].size();   //column size
        bool ans = false;
        int s = 0, e = m-1;        //for row
        while(s <= e){
            int mr = (s+e)/2;         //mid row
            if( (target >= matrix[mr][0])   &&  (target <= matrix[mr][n-1]) ){
                
                int l=0, h=n-1;         //for column
                while(l <= h){
                    int mc = (l+h)/2;       //mid column
                    if(target == matrix[mr][mc]){
                        ans = true;
                        return ans;
                    }
                    else if(target < matrix[mr][mc]){
                        h = mc-1;
                    }
                    else if(target > matrix[mr][mc]){
                        l = mc+1;
                    }
                }
                return ans;
                
            }
            else if(target > matrix[mr][n-1]){
                s = mr+1;
            }
            else if(target < matrix[mr][0]){
                e = mr-1;
            }
        }
        return ans;
    }

int main()
{
    vector<vector<int>> matrix ={ {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    cout<<"Enter target element to search in array : ";
    int target;
    cin>>target;
    bool ans = searchMatrix(matrix, target);
    cout<<ans;
    
    return 0;
}



//////////////////////////////////////////////////////////////////////////////////////////////////


/*

// Optimal (but less than 1st)

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool ans = false;
        int s=0, e=(m*n)-1;
        while(s<=e){
            int mid = (s+e)/2;
            int i = mid/n;
            int j = mid % n;

            if( target == matrix[i][j] ){
                ans = true;
                return ans;
            }
            else if(target > matrix[i][j] ){
                s = mid+1;
            }
            else if(target < matrix[i][j] ){
                e = mid-1;
            }
        }
        return ans;
}


*/
