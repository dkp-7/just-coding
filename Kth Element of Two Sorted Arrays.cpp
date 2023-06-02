// Question :  Kth Element of Two Sorted Arrays
//Question Link (Coding Ninjas) : https://www.codingninjas.com/codestudio/problems/1112629?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0



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
