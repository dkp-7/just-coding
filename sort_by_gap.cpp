//Merge sorted array (Leetcode 88)


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //First, we are putting value of nums2 array in the nums1 array
        int c=0;
        for(int i=m; i<m+n; i++){
            nums1[i] = nums2[c];
            c++;
        }

        //Now, we will sort nums1 array using GAP method
        int gap = ceil((float)(m+n)/2);
        while(gap > 0){
            int p1=0;
            int p2 = p1+gap;
            for(int i=0; p2<(m+n); i++){
                if(nums1[p1] > nums1[p2]){
                    swap(nums1[p1] , nums1[p2]);
                }
                p1++; p2++;
            }
            
            if(gap > 1){
                gap = ceil((float)gap/2);
            }
            else gap = 0;
        }

    }
