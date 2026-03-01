// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        
        
        for(int i=1 ; i<n ; i++) {
            
            int temp = arr[i];
            int j = i - 1;
            
            for( ; j>=0 ; j--){
                if(arr[j] > temp) {
                    arr[j+1] = arr[j];
                }
                else  {
                    break;
                }
            }
            arr[j+1] = temp; 
        }
        
        return ;
    }
};
