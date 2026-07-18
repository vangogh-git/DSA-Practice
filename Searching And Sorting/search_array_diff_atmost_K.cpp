// very basic aaproach
// time complexity : O(n)
// space complexity : O(1)

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        for(int i=0 ; i<n ; i++) {
            if(arr[i] == x) {
                return i;
            }
        }
        return -1;
    }
};


// optimized Solution 
// here the time and space complexities is same but it is more optimized because
// we are taking the advantage of step array and k value for jumping to only useful indexes and skipping unnecessary.

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        
        // edge case when k = 0
        if(k == 0) {
            for(int i=0 ; i<arr.size(); i++) {
                if(arr[i] == x) return i;
            }
        }

        for(int i=0 ; i<arr.size() ; ) {
            if(arr[i] == x) return i;
            
             int jump = max (1 , abs(arr[i]-x)/k);
             i += jump;
        }
        return -1;
    }
};
