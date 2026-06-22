
// Time complexity : O(n)
// space complexity : O(1)

class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        
        vector<int> ans;
        bool found = false;
        int first = 0 , last = 0;
        int n = arr.size();
        
        // edge case
        if(x < arr[0] || x > arr[n-1]) return {-1,-1};
        
        for(int i=0 ; i<arr.size() ; i++) {
            if(!found && arr[i] == x) {
                found = true;
                ans.push_back(i);
            }
            
            if(found && arr[i] != arr[i+1]) {
                ans.push_back(i);
                break;
            }
        }
        
        if(found == false) return {-1,-1};
        return ans;
        
    }
};
