// Time Complexity: O((n*m)log(n*m))
// Space Complexity: O(n*m)
// Brute Force Approach


class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        // first lets create a dynamic vector array
        vector<int> temp;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                temp.push_back(mat[i][j]);
            }
        }
        
        // now just sort the array
        sort(temp.begin() , temp.end());
        
        return temp[(n*m)/2];
        
    }
};


// Optimal Approach
// Using Binary Search in a Matrix
// Time Complexity: O(nlogm * log(maxVal - minVal))
// Space Complexity: O(1)

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        
        // find low high 
        int low = INT_MAX;
        int high = INT_MIN;
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0 ; i<n ; i++) {
            low = min(low , mat[i][0]);
            high = max(high , mat[i][m-1]);
        }
        int ans = -1;
        int req = (n*m+1)/2;
        int mid = low + (high-low)/2;
        // now apply binary search on matrix
        while(low <= high) {
            mid = low + (high-low)/2;
            
            int count = 0;
            
            for(int i=0 ; i<n ; i++) {
                count += upper_bound(mat[i].begin() , mat[i].end() , mid) - mat[i].begin();
            }
            
            if(count >= req){
                ans = mid;
                high = mid - 1;
            }
            
            else{
                low = mid + 1;
            }   
        }
        return ans;
    }
};


