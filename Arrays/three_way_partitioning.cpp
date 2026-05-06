// Time Complexoty: O(n)
// Space Complexity: O(1)
// Using Deutch National Flag Algorithm


class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        
        int low = 0;
        int mid = 0;
        int high = arr.size()-1;
        
        while(mid <= high){
            if(arr[mid] < a) {
                swap(arr[mid] , arr[low]);
                mid++;
                low++;
            }
            
            else if(arr[mid] >= a && arr[mid] <= b) {
                mid++;
            }
            
            else{
                swap(arr[mid] , arr[high]);
                high--;
            }
        }
        
        return ;
    }
};
