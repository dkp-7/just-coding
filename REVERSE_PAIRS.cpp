#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &nums , int s, int e, int mid){
    
    vector<int> temp;
    int total = 0;
    int j = mid+1;
    
    for(int i=s; i<=mid; i++){
        while(j<=e &&  (nums[i] > 2*nums[j]) ){
            j++;
        }
        total += j-(mid+1);
    }
    
    // actual merging starts from here
    int i=s;
    j=mid+1;
    while(i<=mid  &&  j<=e){
        if(nums[i] <= nums[j]){
            temp.push_back(nums[i++]);
        }
        else{
            temp.push_back(nums[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(nums[i++]);
    }
    while(j<=e){
        temp.push_back(nums[j++]);
    }
    int k=0;
    for(int i=s; i<=e; i++){
        nums[i] = temp[k++];
    }
    
    return total;
}

int reversePairs(vector<int> &nums , int s, int e){
    if(s>=e) return 0;
    
    int  mid = (s+e)/2;
    int cnt = reversePairs(nums, s, mid);
    cnt += reversePairs(nums, mid+1, e);
    
    cnt += merge(nums, s, e, mid);
    return cnt;
}

int main()
{
    vector<int> nums = {2,4,3,5,1};
    for(int x=0; x<nums.size(); x++){
        cout<<nums[x]<<"  ";
    }
    cout<<endl;
    
    int s=0;
    int e = nums.size()-1;
    
    int ans = reversePairs(nums, s, e);
    for(int x=0; x<nums.size(); x++){
        cout<<nums[x]<<"  ";
    }
    cout<<endl;
    cout<<"no. of reverse pairs : "<<ans;
    return 0;
}
