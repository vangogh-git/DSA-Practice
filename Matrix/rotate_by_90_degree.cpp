// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        
        int n = mat.size();
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++){
                if(j > i){
                    swap(mat[i][j] , mat[j][i]);                    
                }
            }
        }
        
        // now swap by rows
        for(int i=0 ; i<n/2 ; i++) {
            for(int j=0 ; j<n ; j++) {
                swap(mat[i][j] , mat[n-1-i][j]);
            }
        }
         
    }
};
