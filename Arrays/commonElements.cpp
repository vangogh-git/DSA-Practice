//Using three pointer Approach
//Time Complexity: O(n+m+x)
//Space Complexity: O(n+m+x)

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int n = arr1.size();
        int m = arr2.size();
        int x = arr3.size();
        
        vector<int> ans;
        
        int i=0 , j=0 , k=0;
        
        while(i<n && j<m && k<x) {
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k] ) {
                // insert into ans array
                    if(ans.size() == 0 || ans.back() != arr1[i]) {
                    ans.push_back(arr1[i]);
                }
                
                i++;
                j++;
                k++;
            }
            else {
                int maxi = max({arr1[i], arr2[j], arr3[k]});
                    if(arr1[i] < maxi) i++;
                    if(arr2[j] < maxi) j++;
                    if(arr3[k] < maxi) k++;
            }
        }
        
        return ans;
    }
};
