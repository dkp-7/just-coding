// Merge two sorted Arrays without extra space

/*
input:
vector<int> nums1 = {1,4,7,8,10};
vector<int> nums2 = {2,3,9};
output:
vector<int> nums1 = {1,2,3,4,7};
vector<int> nums2 = {8,9,10};
*/


#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums2, int s, int e){
    int pivot = e;
    int index = s-1;
    
    for(int i=s; i<e; i++){
        if(nums2[i] < nums2[pivot]){
            index++;
            swap(nums2[index] , nums2[i]);
        }
    }
    pivot = index+1;
    swap(nums2[pivot] , nums2[e]);
    return pivot;
}

void qsort(vector<int> &nums2, int s, int e){
    if(s>e){
        return;
    }
    
    int p = partition(nums2, s, e);
    qsort(nums2, s, p-1);
    qsort(nums2, p+1, e);
    return;
}

void qsorting(vector<int> &nums1 , vector<int> &nums2){
    int m=nums1.size();
    int n=nums2.size();
    int s=0, e=n-1;
    
    for(int i=0; i<m; i++){
        if(nums1[i] > nums2[0]){
            swap(nums1[i] , nums2[0]);
            qnsort(nums2, s, e);      //quicksort
        }
    }
    
}


int main()
{
    vector<int> nums1 = {1,4,7,8,10};
    vector<int> nums2 = {2,3,9};
    
    int m=nums1.size();
    int n=nums2.size();
    qsorting(nums1 , nums2);
    for(int i=0; i<m; i++){
        cout<<nums1[i]<<"   ";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<nums2[i]<<"   ";
    }

    return 0;
}
