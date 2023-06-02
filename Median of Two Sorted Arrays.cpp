//Leetcode : 4. Median of Two Sorted Arrays


// Most Optimal : Using Binary Search

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double median = 0.0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2 < n1) return findMedianSortedArrays(nums2 , nums1);

        int low = 0;
        int high = n1;
        while(low <= high){
            int cut1 = (low + high) / 2;
            int cut2 = (n1+n2+1)/2 - cut1;     // (n1+n2+1) is length of left half

            int left1 = (cut1 == 0)?  INT_MIN : nums1[cut1-1];
            int left2 = (cut2 == 0)?  INT_MIN : nums2[cut2-1];
            int right1 = (cut1 == n1)?  INT_MAX : nums1[cut1];
            int right2 = (cut2 == n2)?  INT_MAX : nums2[cut2];

            if(left1 <= right2   &&   left2 <= right1){

                if((n1+n2)%2 == 0){
                    median = (double)(max(left1,left2) + min(right1,right2)) / 2.0;
                    return median;
                }
                else{
                    median = (double)(max(left1,left2));
                    return median;
                }
            }
            else if(left1 > right2){
                high = cut1-1;
            }
            else{      //if(left2 > right1)
                low = cut1 + 1;
            }
            //IMP: here we have performed operations for binary search only on single array whose length is less
        }
        return median;
    }
};


------------------------------------------------------------------------------------------------------------------------------------

//using Optimsed Merge Sort approach to extract mid elements in sorted array (not using array to store all elements)
// And as soon as we get both mid elements we break the loop

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();
        int mid = (m+n)/2;
        int i=0, j=0, cnt = 0;
        int md1 =0 , md2 = 0;
        //vector<int> arr;
        
        while(i<m  &&  j<n){
            if(nums1[i] <= nums2[j]){
                //arr.push_back(nums1[i]);
                cnt++;
                if(cnt == mid){md1 = nums1[i];}
                if(cnt == mid+1){
                    md2 = nums1[i];
                    break;
                }
                i++;   
            }
            else{
                //arr.push_back(nums2[j]);
                cnt++;
                if(cnt == mid){md1 = nums2[j];}
                if(cnt == mid+1){
                    md2 = nums2[j];
                    break;
                }
                j++;
            }
        }
        
        while(i<m){
            //arr.push_back(nums1[i]);
            cnt++;
            if(cnt == mid){md1 = nums1[i];}
            if(cnt == mid+1){
                md2 = nums1[i];
                break;
            }
            i++;
        }
        while(j < n){
            //arr.push_back(nums2[j]);
            cnt++;
            if(cnt == mid){md1 = nums2[j];}
            if(cnt == mid+1){
                md2 = nums2[j];
                break;
            }
            j++;
 
        }
        double median = 0;
        if((m+n)%2 == 0){
            median = (md1+md2) / 2.0;
            }
        else{
            median = (double)md2; 
        }
        
        return median;
    }
};


--------------------------------------------------------------------------------------------------------------------------

// using merge sort

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        int mid = (m+n)/2;
        int i=0, j=0;
        vector<int> arr;
        
        while(i<m  &&  j<n){
            if(nums1[i] <= nums2[j]){
                arr.push_back(nums1[i]);
                i++;   
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }  
        while(i<m){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            arr.push_back(nums2[j]);
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
