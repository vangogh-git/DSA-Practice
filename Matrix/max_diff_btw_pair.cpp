// Time Comeplexity: O(n^2)
// Space Complexity: O(n^2)
// we create e separate matrix which contains the suffix max 


class Solution {
  public:
    int findMaxValue(vector<vector<int>>& mat, int N) {
        
        vector<vector<int>> max_mat(N , vector<int>(N));
        
        // fill the max matrix
        max_mat[N-1][N-1] = mat[N-1][N-1];
        
        // fill last col
        for(int j=N-2 ; j>=0 ; j--) {
            max_mat[N-1][j] = max(max_mat[N-1][j+1] , mat[N-1][j]);
        }
        
        for(int i=N-2 ; i>= 0 ; i--) {
            max_mat[i][N-1] = max(max_mat[i+1][N-1] , mat[i][N-1]);
        }
        
        // fill in the mid values
        for(int i=N-2 ; i>=0 ; i--) {
            for(int j=N-2 ; j>=0 ; j--) {
                max_mat[i][j] = max(max_mat[i+1][j] , max(max_mat[i][j+1] , mat[i][j]));
            }
        }
        
        int ans = INT_MIN;
        
        for(int i=0 ; i<N-1 ; i++) {
            for(int j=0 ; j<N-1 ; j++) {
                ans = max(ans , max_mat[i+1][j+1] - mat[i][j]);
            }
        }
        
        return ans;
        
    }
};
