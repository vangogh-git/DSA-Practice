// Time Complexity : O(n+m)
// Space Complexity: O(1)
// Linear Search in 2D Array / Matrix


class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int store = -1;
        for(int i=0 ; i<n ; i++) {
            if( x  >= mat[i][0] && x <= mat[i][m-1] ) {
                store = i;
            }
        }
        
        for(int j=0 ; j<m ; j++) {
            if(store == -1) {
                return false;
            }
            
            if(mat[store][j] == x) {
                return true;
            }
        }
        
        return false;
    }
};
