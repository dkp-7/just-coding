// Leetcode :  215. Kth Largest Element in an Array
//Using Quick Sort method to fix pivot element at its correct position & moving elements smaller to pivot at its left and vice versa
// then we count the elements remaining from pivot to end
// after that, we decide whether to move left / right of the pivot to search for the kth largest element accordingly

class Solution {
public:

    void qSort(vector<int>& nums, int k, int s, int e, int n, int &ans){

        if(s > e) return;
        int pivot = nums[e];
        int i = s-1;
        for(int j=s; j<e; j++){
            if(nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        int p = i+1;
        swap(nums[p] , nums[e]);

        int cnt = n-p;
        cout<<cnt<<endl;
        if(k == cnt){
            ans = nums[p];
            return;
        }
        else if(k < cnt){
            return qSort(nums, k, p+1, e, n, ans);
        }
        else return qSort(nums, k, s, p-1, n, ans);

    }

    int findKthLargest(vector<int>& nums, int k) { 
        int n = nums.size();
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        qSort(nums , k , s , e , n ,ans);
        return ans;
    }
};
