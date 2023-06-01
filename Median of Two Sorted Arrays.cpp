//Leetcode : 4. Median of Two Sorted Arrays


// using merge sort

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //using merge Sort approach to extract mid elements in sorted array
        int m = nums1.size();
        int n = nums2.size();
        cout<<"m: "<<m<<endl;
        cout<<"n :"<<n<<endl;
        int mid = (m+n)/2;
        cout<<"mid :"<<mid<<endl; 
        int i=0, j=0, cnt = 0;
        int md1 =0 , md2 = 0;
        vector<int> arr;
        
        while(i<m  &&  j<n){
            if(nums1[i] <= nums2[j]){
                arr.push_back(nums1[i]);
                cout<<cnt<<" : "<< arr[cnt]<<endl;
                cnt++;
                i++;   
            }
            else{
                arr.push_back(nums2[j]);
                cout<<cnt<<" : "<< arr[cnt]<<endl;
                cnt++;
                j++;
            }
        }
        
        while(i<m){
            arr.push_back(nums1[i]);
            cout<<cnt<<" : "<< arr[cnt]<<endl;
            cnt++;
            i++;
        }
        while(j < n){
            arr.push_back(nums2[j]);
            cout<<cnt<<" : "<< arr[cnt]<<endl;
            cnt++;
            j++;
 
        }
        double median = 0;
        if((m+n)%2 == 0){
            median = (double)( arr[mid-1] + arr[mid] ) / 2.0;
            }
        else{
            median = (double)arr[mid]; 
        }
        
        return median;
    }
};
