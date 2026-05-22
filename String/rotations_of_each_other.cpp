// Time Complexity : O(n)
// Space Complexity : O(n)
// String concatenation

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
    
        
        string temp = s1 + s1;
        
        if(temp.find(s2) != -1 && s1.size() == s2.size()){
            return true;
        }
        
        return false;
        
    }
};
