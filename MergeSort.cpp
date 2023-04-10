#include <iostream>
#include <vector>

using namespace std;

    void compare(vector<int> &nums , int l, int r, int mid){
        
        if(l>=r){
            return;
        }
        
        int i=l;
        int j=mid+1;
        int s=l;
        vector<int> temp;
        while(i<=mid  &&  j<=r){
            
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }
            else if(nums[j] < nums[i]){
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=r){
            temp.push_back(nums[j++]);
        }
        int c=0;
        for(int k=l; k<=r; k++){
            nums[k] = temp[c++];
        }
        return;
    }
    
    void helper(vector<int> &nums , int l, int r, int mid){
        if(l>=r){
            return;
        }
        
        helper(nums , l, mid, (l+mid)/2);
        helper(nums , mid+1 , r , (mid+1+r)/2);
        compare(nums , l, r , mid);
        return;
    }

    void MergeSort(vector<int>& nums) {
        int n = nums.size();
        
        //Merge Sort
        int l=0; int r=n-1;
        int mid = (l+r) / 2;
        helper(nums , l, r, mid);
        return;
        
    }


int main()
{
    vector<int> nums = {2,6,4,2,9,1,1,0};
    MergeSort(nums);
    for(int x=0; x<nums.size(); x++){
        cout<<nums[x]<<"  ";
    }
    return 0;
}
