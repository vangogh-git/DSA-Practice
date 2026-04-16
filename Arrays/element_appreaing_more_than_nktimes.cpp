// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        
        // create a temp array for mapping using unordered maps
        unordered_map<int, int> m;
        int n = arr.size();
        
        int check = n / k;
        
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            int index = arr[i];
            if(m[index] == -1){
                continue;
            }
            m[index]++;
            // check if the count in the map is greater than check value
            if(m[index] > check) {
                // mark as visited
                m[index] = -1;
                count++;
            }
        }
        
        return count++;
        
        
    }
};
