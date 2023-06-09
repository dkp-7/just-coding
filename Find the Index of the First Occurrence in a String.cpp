//  Leetcode :   28. Find the Index of the First Occurrence in a String


// More optimal using 2 pointer

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.length();
        int len = needle.length();
        
        if(haystack == needle) return 0;

        for(int i=0; i<n-len+1; i++){
            int ls=i;  int lt=0;
            int rs=i+len-1;    int rt=lt+len-1;
            while(lt<=len  &&  rt>=0 && haystack[ls]==needle[lt]  &&  haystack[rs]==needle[rt]){
                ls++;  lt++;
                rs--;  rt--;
            }
            if(ls>rs) return i;
        }
        return -1;
    }
};

--------------------------------------------------------------------------------
    
class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.length();
        int len = needle.length();

        for(int i=0; i<n-len+1; i++){
            if(haystack.substr(i,len) == needle) return i;
        }
        return -1;
    }
};
