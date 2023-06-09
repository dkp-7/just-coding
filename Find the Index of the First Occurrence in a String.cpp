//  Leetcode :   28. Find the Index of the First Occurrence in a String


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
