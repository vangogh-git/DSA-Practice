// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
  public:
    
    bool subArrayExists(vector<int>& arr) {
       
        unordered_map<int , bool> m;
        
        int sum = 0;
        for(int i=0 ; i<arr.size() ; i++) {
            sum += arr[i];
            if(sum == 0 || m[sum] == true){
                return true;
            }
            m[sum] = true;
        }
        
        return false;
    }
};
