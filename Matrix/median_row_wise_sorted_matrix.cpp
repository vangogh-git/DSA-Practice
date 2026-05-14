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
