// Leetcode :   8. String to Integer (atoi)



----------------------------------------------------------------------------------

class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.length();
        int ans = 0;
        bool first_digit = false;
        bool neg = false;

        for(int i=0; i<n; i++){
            if(s[i] == ' ') continue;

            else if(s[i]=='-' ||  s[i]=='+'){
                neg = (s[i]=='-') ? true : false;
                if(isdigit(s[i+1]) == false) return 0;
            }

            else if( isdigit(s[i]) ){

                if(first_digit == false  &&  s[i]=='0'){
                    if(isdigit(s[i+1]) == false) return 0;
                    continue;
                } 

                if(first_digit == false){
                    ans = (int)s[i] - '0';
                    first_digit = true;
                    if(isdigit(s[i+1]) == false) break;
                }
                else{
                    if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)){
                        return(neg == false)? INT_MAX : INT_MIN;
                    } 
                    ans = ans*10 + ( (int)s[i] -'0');
                    if(isdigit(s[i+1]) == false) break;
                }
            }
            else break;
        }
        if(neg == true){
            ans = -1 * ans;
        }
        return ans;
    }
};
