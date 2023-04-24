//  Leetcode :     3. Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int longest = 0;
        unordered_set<char> set;
 
        int left = 0;
        int n = s.length();
        
        for(int right=0; right<n; right++){
            
            while(left<right  &&  set.find(s[right]) != set.end()){
                set.erase(s[left]);
                left++;
            }
            
            set.insert(s[right]);
            longest = max(longest , right-left+1);
            
        }
        return longest;
    }
};




/*


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int longest = 1;
        unordered_set<char> set;
 
        int left = 0, right=1;
        
        set.insert(s[0]);
        while(right<n){
            
            while(left<right  &&  set.find(s[right]) != set.end()){
                    set.erase(s[left]);
                    left++;
                }
            
            set.insert(s[right]);
            longest = max(longest , right-left+1);
            right++;
        }
        return longest;
    }
};


//////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int longest = 0;
        unordered_set<char> set;
 
        int left = 0;
        int n = s.length();
        
        for(int right=0; right<n; right++){
            
            if(set.find(s[right]) != set.end()){
                while(left<right  &&  set.find(s[right]) != set.end()){
                    set.erase(s[left]);
                    left++;
                }
            }
            
            set.insert(s[right]);
            longest = max(longest , right-left+1);
            
        }
        return longest;
    }
};

*/
