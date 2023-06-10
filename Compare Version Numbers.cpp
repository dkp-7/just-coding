//Leetcode :  165. Compare Version Numbers


class Solution {
public:
    int compareVersion(string version1, string version2) {

        int n1 = version1.length();
        int n2 = version2.length();
        int sum1=0, sum2=0;
        int i=0, j=0;

        while((i < n1)  ||  (j < n2)){
            sum1=0;
            sum2=0;
            while(i<n1  &&  version1[i] != '.'){
                sum1 = sum1*10 + (version1[i]-'0');
                i++;
            }
            while(j<n2  &&  version2[j] != '.'){
                sum2 = sum2*10 + (version2[j]-'0');
                j++;
            }
            if(sum1 > sum2) return 1;
            else if(sum2 > sum1) return -1;
            i++;  j++;
        }
        return 0;
    }
};

------------------------------------------------------------------------


class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        if(version1 == version2) return 0;
        int n1 = version1.length();
        int n2 = version2.length();
        int maxlen = max(n1,n2);
        int p1=-1, p2=-1, sum1=0, sum2=0;
        for(int i=0; i<maxlen; i++){
            
            if(sum1 > sum2) return 1;
            else if(sum2 > sum1) return -1;

            p1++;  p2++; sum1=0; sum2=0;

            while(p1<n1  &&  version1[p1] != '.'){
                if(sum1>=1)  sum1 = sum1*10 + version1[p1]-'0';
                else sum1 += version1[p1]-'0';
                p1++;
            }

            while(p2<n2  &&  version2[p2] != '.'){
                if(sum2>=1)  sum2 = sum2*10 + version2[p2]-'0';
                else sum2 += version2[p2]-'0';
                p2++;
            }

        }

        if(sum1 > sum2)  return 1;
        else if(sum2 > sum1)  return -1;
        else return 0;
    }
};
