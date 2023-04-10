#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int s, int e){
    int p = e;
    int border = s-1;
    for(int i=s; i<=e; i++){
        if(nums[i] < nums[p]){
            border++;
            swap(nums[border] , nums[i]);
        }
    }
    p = border+1;
    swap(nums[p] , nums[e]);
    return p;
}

void quickSort(vector<int> &nums, int s, int e){
    
    if(s>=e){
        return;
    }
    
    int p = partition(nums, s, e);
    
    quickSort(nums , s , p-1);
    quickSort(nums , p+1 , e);
}

int main()
{
    vector<int>nums = {6,3,5,1,0,5};
    int n = nums.size();
    int s=0;
    int e = n-1;
    quickSort(nums, s, e);
    for(int i=0; i<n; i++){
        cout<<nums[i]<<"  ";
    }
    
    return 0;
}
