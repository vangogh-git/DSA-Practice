// time complexity: O(n^2)
// space complexity: O(1)



class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int z = 0;
        int n = arr.size();
        
        sort(arr.begin() , arr.end());
        
        for(int i=0 ; i<n ; i++) {
            z = arr[i];
            int diff = target - z;
            // apply two pointer approach
            int j = i+1;
            int k = n-1;
            while( j<k ) {
                if(arr[j] + arr[k] == diff) {
                    return true;
                }
                else if(arr[j] + arr[k] < diff) {
                    j++;
                }
                
                else{
                    k--;
                }
            }
        }
        
        return false;
    }
};
