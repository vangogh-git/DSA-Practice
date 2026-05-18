// Time Complexity : O(n*m)
// Space Complexity: O(n*m) + O(m) + O(m) = O(n*m)
// the key here is using an unordered set which has a property that it only stores unique element in it


#include <unordered_set>

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // we are going to use set here
    // sets are specialised to contain only unique elemets
    // map will store the count of all the unique elements in each row

    int n = mat.size();
    int m = mat[0].size();

    unordered_map<int,int> mapping;
    vector<int> ans;
    
    for(int i=0 ; i<n ; i++) {

        unordered_set<int> visited;

        for(int j=0 ; j<m ; j++) {
            
            if(visited.find(mat[i][j]) == visited.end() ) {
                // you did not find the element
                // hence your element is unique
                
                visited.insert(mat[i][j]);
                mapping[mat[i][j]] ++;
            }
        }
    }

    // now you have the mapping of all elements 
    for(auto it: mapping) {
        if(it.second == n) {
            ans.push_back(it.first);
        }
    }

    return ans;

}
