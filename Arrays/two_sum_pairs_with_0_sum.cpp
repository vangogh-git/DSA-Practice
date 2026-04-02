// User function template for C++

// Time Complexity: O(nlog(n))
// Space Complexity: O(1)

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        
        vector<vector<int>> ans;
        int temp1 , temp2;
        // sort it 
        sort(arr.begin() , arr.end() );
        
        // two pointer approach
        int n = arr.size();
        
        int i=0 , j=n-1;
        
        while(i < j) {
            if(arr[i] + arr[j] < 0) {
                i++;
            }
            
            else if(arr[i] + arr[j] > 0) {
                j--;
            }
            else{
                if(arr[i] != temp1 && arr[j] != temp2)
                ans.push_back({arr[i] , arr[j]});
                temp1 = arr[i];
                temp2 = arr[j];
                i++;
                j--;
            }
        }
        
        return ans;
    }
};
