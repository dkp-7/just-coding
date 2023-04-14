#include <bits/stdc++.h> 
#include <vector>

#include <iostream>

using namespace std;

void compare(int arr[], int s, int e, int &c){

    int mid = (s+e)/2;
    int i=s, j=mid+1;

    vector<int> temp((e-s+1),0);
    int k=0;

    while((i<=mid) && (j<=e)){

        if(arr[i] > arr[j]){
            temp[k] = arr[j];
            j++; k++;
            c = c + (mid-i)+1;
        }
        else{              //if(arr[i] <= arr[j])
            temp[k] = arr[i];
            i++; k++;
        }
    }
    while(i<=mid){
        temp[k] = arr[i];
        i++; k++;
    }
    while(j<=e){
        temp[k] = arr[j];
        j++; k++;
    }
    k=0;
    for(int i=s; i<=e; i++){
        arr[i] = temp[k++];
    }

    return;
}

void msort(int arr[], int s, int e, int &c){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    msort(arr, s, mid, c);
    msort(arr, mid+1, e, c);
    compare(arr, s, e, c);
    return;
}

int getInversions(int arr[], int n){
    // Write your code here.
    int c=0;
    int s = 0;
    int e = n-1;
    msort(arr, s, e, c);
    int ans = c;
    return ans;
}


int main()
{
    int arr[] = {2,5,1,3,4};
    int n = 5;
    int ans = getInversions(arr, n);
    cout<<ans;
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*

OR  for (long long)  datatype


#include <bits/stdc++.h> 

using namespace std;

void compare(long long *arr, int s, int e, int &c){

    int mid = (s+e)/2;
    int i=s, j=mid+1;

    vector<int> temp((e-s+1),0);
    int k=0;

    while((i<=mid) && (j<=e)){

        if(arr[i] > arr[j]){
            temp[k] = arr[j];
            j++; k++;
            c = c + (mid-i)+1;
        }
        else{              //if(arr[i] <= arr[j])
            temp[k] = arr[i];
            i++; k++;
        }
    }
    while(i<=mid){
        temp[k] = arr[i];
        i++; k++;
    }
    while(j<=e){
        temp[k] = arr[j];
        j++; k++;
    }
    k=0;
    for(int i=s; i<=e; i++){
        arr[i] = temp[k++];
    }

    return;
}

void msort(long long *arr, int s, int e, int &c){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    msort(arr, s, mid, c);
    msort(arr, mid+1, e, c);
    compare(arr, s, e, c);
    return;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int c=0;
    int s = 0;
    int e = n-1;
    msort(arr, s, e, c);
    long long ans = (long long)c;
    return ans;
}


int main()
{
    long long arr[] = {2,5,1,3,4};
    int n = 5;
    long long ans = getInversions(arr, n);
    cout<<ans;
    return 0;
}



*/
