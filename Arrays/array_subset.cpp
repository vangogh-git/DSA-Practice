// time complexity: O(n+m)
// space complexity: O(n)


class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        
        unordered_map<int,int> mp;
        int n = a.size();
        int m = b.size();
        
        for(int i=0 ; i<n ; i++) {
            mp[a[i]]++;
        }
        
        // now check if b is there in map or not
        for(int i=0 ; i<m ; i++) {
            int element = b[i];
            
            if(mp[element] == 0) {
                return false;
            }
            
            mp[element]--;
        }
        
        return true;
    }
};
