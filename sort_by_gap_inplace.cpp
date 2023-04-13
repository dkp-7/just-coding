// gap method to sort 2 arrays IN-PLACE in 2 differnt arrays

#include <bits/stdc++.h>

using namespace std;

void merge(int ar1[], int ar2[], int m, int n){
    
    int gap = ceil( (float)(m+n)/2);
    
    while(gap > 0){
        int p1=0;
        int p2 = gap;
    
        while(p2 < (m+n)){
            if((p2 < m)  &&  (ar1[p1] > ar1[p2])){
                swap(ar1[p1] , ar1[p2]);
            }
            
            else if( (p1<m) && (p2>=m) && (ar1[p1] > ar2[p2-m]) ){
                swap(ar1[p1] , ar2[p2-m]);
            }
            
            else if( (p1>=m) && (p2>=m) && (ar2[p1-m] > ar2[p2-m]) ){
                swap(ar2[p1-m] , ar2[p2-m]);
            }
            p1++;  p2++;
        }
        
        if(gap == 1){
            gap = 0;
        }
        else{
            gap = ceil((float)gap / 2);
        }
    }
    
}


int main() {
  int arr1[] = {1,4,7,8,10};
  int arr2[] = {2,3,9};
  int m=5;   // size of array 1
  int n=3;   // size of array 2
  cout << "Before merge:" << endl;
  for (int i = 0; i < m; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;
  merge(arr1, arr2, 5, 3);
  cout << "After merge:" << endl;
  for (int i = 0; i < m; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << arr2[i] << " ";
  }

}
