// Using three pointer Approach
// Time Complexity: O(n+m+x)
// Space Complexity: O(n+m+x)

class Solution {
  public:
    
    vector<int> unionElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        
        int n = arr1.size();
        int m = arr2.size();
        int x = arr3.size();
        
        vector<int> ans;
        
        int i = 0 , j = 0 , k = 0;
        
        while(i<n && j<m && k<x) {
            if(arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
                if(ans.size() == 0 || ans.back() != arr1[i]) {
                    ans.push_back(arr1[i]);
                }
                i++;
            }
            
            else if(arr1[i] <= arr2[j] && arr1[i] > arr3[k]) {
              if(ans.size() == 0 || ans.back() != arr3[k]) {
                    ans.push_back(arr3[k]);
                }
                k++;  
            }
            
            else if(arr1[i] > arr2[j] && arr1[i] <= arr3[k]){
                if(ans.size() == 0 || ans.back() != arr2[j]) {
                    ans.push_back(arr2[j]);
                }
                j++;
            }
            
            else{
                // ( arr1[i] > arr2[j] && arr1[i] > arr3[k] )
                // different case
                // find the minimum of the other two arrays and insert it into the array
                // increment the postion of that array which gave you the minimum value
                if(arr2[j] <= arr3[k]) {
                    if(ans.size() == 0 || ans.back() != arr2[j]) {
                    ans.push_back(arr2[j]);
                    }
                    j++;
                }
                else {
                    if(ans.size() == 0 || ans.back() != arr3[k]) {
                    ans.push_back(arr3[k]);
                    }
                    k++;
                }
            }
        }
        
        while(i<n && j<m) {
            int mini = min(arr1[i] , arr2[j]);
            if(ans.size() == 0 || ans.back() != mini) {
                    ans.push_back(mini);
                }
            if(arr1[i] == mini) {
                i++;
            }
            else{
                j++;
            }
        }
        
        while(i<n && k<x) {
            int mini = min(arr1[i] , arr3[k]);
            if(ans.size() == 0 || ans.back() != mini) {
                    ans.push_back(mini);
                }
            if(arr1[i] == mini) {
                i++;
            }
            else{
                k++;
            }
        }
        
        while(j<m && k<x) {
            int mini = min(arr2[j] , arr3[k]);
            if(ans.size() == 0 || ans.back() != mini) {
                    ans.push_back(mini);
                }
            if(arr2[j] == mini) {
                j++;
            }
            else{
                k++;
            }
        }
        
        while(i < n) {
           if(ans.size() == 0 || ans.back() != arr1[i]) {
                    ans.push_back(arr1[i]);
                }
                i++; 
        }
        
        while(j < m) {
            if(ans.size() == 0 || ans.back() != arr2[j]) {
                    ans.push_back(arr2[j]);
                }
                j++; 
        }
        
        while(k < x) {
            if(ans.size() == 0 || ans.back() != arr3[k]) {
                    ans.push_back(arr3[k]);
                }
                k++;
        }
        
        return ans;
        
    }
};
