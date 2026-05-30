// Time Complexity : O(n * m * k)
// Space Complexity : O(1)


class Solution {
    private: 
    vector<int> checkDirection(int row , int col , int &n , int &m , string &word , vector<vector<char>> &grid) {
        // right
        bool right = true;
        for(int k=0 ; k<word.size() ; k++) {
            int newCol = col + k;
            if(newCol >= m || grid[row][newCol] != word[k]) {
                right = false;
                break;
            }
        }
        // left
        bool left = true;
        for(int k=0 ; k<word.size() ; k++) {
            int newCol = col - k;
            if(newCol < 0 || grid[row][newCol] != word[k]) {
                left = false;
                break;
            }
        }
        // up
        bool up = true;
        for(int k=0 ; k<word.size() ; k++) {
            int newRow = row - k;
            if(newRow < 0 || grid[newRow][col] != word[k]) {
                up = false;
                break;
            }
        }
        // down
        bool down = true;
        for(int k=0 ; k<word.size() ; k++) {
            int newRow = row + k;
            if(newRow >= n || grid[newRow][col] != word[k]) {
                down = false;
                break;
            }
        }
        // diagonally down right
        bool down_right = true;
        for(int k=0 ; k<word.size() ; k++) {
            int newRow = row + k;
            int newCol = col + k;
            if(newRow >= n || newCol >= m ||  grid[newRow][newCol] != word[k]) {
                down_right = false;
                break;
            }
        }
        // diagonally down left
        bool down_left = true;
         for(int k=0 ; k<word.size() ; k++) {
            int newRow = row + k;
            int newCol = col - k;
            if(newRow >= n || newCol < 0 ||  grid[newRow][newCol] != word[k]) {
                down_left = false;
                break;
            }
        }
        // diagonally up right
        bool up_right = true;
         for(int k=0 ; k<word.size() ; k++) {
            int newRow = row - k;
            int newCol = col + k;
            if(newRow < 0 || newCol >= m ||  grid[newRow][newCol] != word[k]) {
                up_right = false;
                break;
            }
        }
        // diagonally up left
        bool up_left = true;
         for(int k=0 ; k<word.size() ; k++) {
            int newRow = row - k;
            int newCol = col - k;
            if(newRow < 0 || newCol < 0 ||  grid[newRow][newCol] != word[k]) {
                up_left = false;
                break;
            }
        }
        // check if any direction is true 
        // then u can approve the cordinates and put them in 
        // your answer
        if(right || left || up || down || down_right || down_left || up_right || up_left) {
            // row  is correct
            //col is correct
            return {row,col};
        }
        else{
            return {-1,-1};
        }
    }
     
  public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
        // Code here
        vector<vector<int>> ans;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                    if(grid[i][j] == word[0]) {
                    vector<int> temp = checkDirection(i , j , n , m , word , grid);
                    if(temp[0] == -1 || temp[1] == -1) continue;
                    ans.push_back(temp);
                }
            }
        } 
        
        return ans;
    }
};
