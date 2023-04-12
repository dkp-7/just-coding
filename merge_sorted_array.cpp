/*       Leetcode : Question 88
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

note : store the answer in nums1
*/


//Best Answer is 1st one, if there is more chance that both of the array size is not 0.  
// And for competetive coding also this soln is better since the test case will definitely have array sizes that is not equal to 0
// And this soln will cover all the cases, so no unnecessary checking of "if" condition



void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

            vector<int> temp(m,0);
            for(int i=0; i<m; i++){
                temp[i] = nums1[i];
            }

            int i=0, j=0, c=0;
            while(i<m   &&  j<n){
                if(temp[i] > nums2[j]){
                    nums1[c] = nums2[j];
                    j++; c++;
                }
                else{  //if(temp[i] < nums2[j]){
                    nums1[c] = temp[i];
                    i++; c++;
                }
            }

            while(i<m  &&  c<(m+n)){
                nums1[c] = temp[i];
                i++; c++;
            }
            while(j<n  &&  c<(m+n)){
                nums1[c] = nums2[j];
                j++; c++;
}




/*         2nd solution, this will be much better if the array with size 0 is more frequent

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        
        if( (m!=0) && (n!=0) ){
            vector<int> temp(m,0);
            for(int i=0; i<m; i++){
                temp[i] = nums1[i];
            }

            int i=0, j=0, c=0;
            while(i<m   &&  j<n){
                if(temp[i] > nums2[j]){
                    nums1[c] = nums2[j];
                    j++; c++;
                }
                else if(temp[i] <= nums2[j]){
                    nums1[c] = temp[i];
                    i++; c++;
                }
            }

            while(i<m  &&  c<(m+n)){
                nums1[c] = temp[i];
                i++; c++;
            }
            while(j<n  &&  c<(m+n)){
                nums1[c] = nums2[j];
                j++; c++;
            }
        }

        else if((m == 0)  &&  (n!=0)){
            for(int i=0; i<n; i++){
                nums1[i] = nums2[i];
            }
        } 
}

*/
