// Leetcode :  242. Valid Anagram


// Using Hashing                tc : O(n)     SC: O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
    
        if(n1 != n2) return false;
        unordered_map<char,int> um;

        for(int i=0; i<n1; i++){
            um[s[i]]++;
        }
        for(int j=0; j<n2; j++){
            if( um[t[j]] == 0)  return false;
            um[t[j]]--;
        }
        return true;
    }
};


----------------------------------------------------------------
    
    
// Using Sorting              tc : O(n logn)     SC: O(1)
    
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        if(s == t) return true;
        else return false;
    }
};
