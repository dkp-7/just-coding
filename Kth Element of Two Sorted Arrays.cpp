// Question :  Kth Element of Two Sorted Arrays
//Question Link (Coding Ninjas) : https://www.codingninjas.com/codestudio/problems/1112629?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


// Most Optimal using Binary Search

#include <bits/stdc++.h>

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    
    if(m > n) return ninjaAndLadoos(row2, row1, n, m, k);
    //Defining range of left half
    int low = max(0 , k-n);
    int high = min(m , k);
    
    while(low <= high){
        int cut1 = (low + high)/2;
        int cut2 = k - cut1;
        
        int left1 = (cut1 == 0)? INT_MIN : row1[cut1-1];
        int left2 = (cut2 == 0)? INT_MIN : row2[cut2-1];
        int right1 = (cut1 == m)? INT_MAX : row1[cut1];
        int right2 = (cut2 == n)? INT_MAX : row2[cut2];

        if(left1 <= right2   &&   left2 <= right1){
            return max(left1 , left2);
        }
        else if(left1 > right2){
            high = cut1-1;
        } else {        // if(left2 > right1)
            low = cut1+1;
        }
    }
    return 0;
    
}


----------------------------------------------------------------------------------------------------------------------------


// Using Merge Sort but no extra space

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {

    //vector<int> merge;
    int ans;
    int i=0, j=0;
    int cnt = 0;
    while(i<m  &&  j<n){
        if(row1[i] <= row2[j]){
            cnt++;
            if(cnt == k){
                ans = row1[i];
                break;
            }
            i++;
        }
        else{
            cnt++;
            if(cnt == k){
                ans = row2[j];
                break;
            }
            j++;
        }
    }
    while(i < m){
        cnt++;
        if(cnt == k){
            ans = row1[i];
            break;
        }
        i++;
    }
    while(j < n){
        cnt++;
        if(cnt == k){
            ans = row2[j];
            break;
        }
        j++;
    }  

    return ans;
}



---------------------------------------------------------------------------------------------------------------------------------

//Using Merge Sort + Extra Space of O(m+n)

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    
    vector<int> merge;
    int i=0, j=0;
    while(i<m  &&  j<n){
        if(row1[i] <= row2[j]){
            merge.push_back(row1[i]);
            i++;
        }
        else{
            merge.push_back(row2[j]);
            j++;
        }
    }
    while(i < m){
        merge.push_back(row1[i]);
        i++;
    }
    while(j < n){
        merge.push_back(row2[j]);
        j++;
    }  
    //merge sort completed

    int ans = merge[k-1]; 
    return ans;
}
