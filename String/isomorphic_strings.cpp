// Time Complexity : O(n)
// Space Complexity :O(n)
// Used Mapping Approach

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        if(s1.size() != s2.size() ) {
            return false;
        }
        
        unordered_map<char,char> m1 , m2;
        
        int n = s1.size();
        
        for(int i=0 ; i<n ; i++) {
            char c1 = s1[i];
            char c2 = s2[i];
            
            if(m1.count(c1)) {
                // found
                if(m1[c1] != c2) return false;
            }
            else{
                // not found c1
                m1[c1] = c2;
            }
            
            if(m2.count(c2)) {
                // found
                if(m2[c2] != c1) return false;
                
            }
            else{
                // not found c2
                m2[c2] = c1;
            }
        }
        
        return true;
    }
};

