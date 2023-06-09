// Leetcode :   8. String to Integer (atoi)


class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0;
        int sign = 1;
        int count = 0;// count optional sign number
        int res = 0;
        if (s.empty())return 0;
        
        //Discard whitespaces in the beginning
        while(i < s.size() && s[i] == ' ')
            i++;
        
        //Check if optional sign if it exists
        while(i < s.size() && (s[i] == '+' || s[i] == '-')){
            count++;
            sign = (s[i++] == '-')? -1 : 1;
        }
        if(count>1) count = 0;
        else count = 1;
        
        //Build the result and check for overflow/underflow condition
        while(i < s.size() && s[i]>='0' && s[i]<='9')                     //   or     while(i < s.size() && (isdigit(s[i]) == true))
        {
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)){
                return(sign == 1)? INT_MAX : INT_MIN;
            } 
            res = res * 10 + (s[i++] - '0');
        }
      return res * sign*count;
    }
};


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
