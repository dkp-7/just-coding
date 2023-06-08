// Leetcode :  13. Roman to Integer


//Brute force       TC: O(N)      SC :  O(7)

class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.length();
        unordered_map<char,int> um = { {'I',1} , {'V',5} , {'X',10} , {'L',50} , {'C',100} , {'D',500} , {'M',1000} };

        int sum = 0; int double1 = 0; int single = 0;

        int i = 0;
        while(i < n-1){

            if(s.substr(i,2) == "IV"){
                sum += 4;
                double1 += 2;
                i = i+2;
            }

            else if(s.substr(i,2) == "IX"){
                sum += 9;
                double1 += 2;
                i = i+2;
            }

            else if(s.substr(i,2) == "XL"){
                sum += 40;
                double1 += 2;
                i = i+2;
            }

            else if(s.substr(i,2) == "XC"){
                sum += 90;
                double1 += 2;
                i = i+2;
            }

            else if(s.substr(i,2) == "CD"){
                sum += 400;
                double1 += 2;
                i = i+2;
            }

            else if(s.substr(i,2) == "CM"){
                sum += 900;
                double1 += 2;
                i = i+2;
            }

            else{
                sum += um[s[i]];
                single++;
                i++;
            }

        }
        if( (double1 + single)  ==  n-1){
            sum += um[s[n-1]]; 
        }
        return sum;

    }
};
