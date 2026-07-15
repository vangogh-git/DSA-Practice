// Brute Force Approach
// Time Complexity : O(n^2)
// Space Complexity : O(1)


class Solution {
  public:
    int minSwaps(vector<int>& arr) {
    
        int cnt = 0;
        for(int i=0 ; i<arr.size() ; i++) {
            int mini = arr[i];
            int index = -1;
            for(int j=i+1 ; j <arr.size() ; j++) {
                if(arr[j] < mini) {
                    mini = arr[j];
                    index = j;
                }
            }
            if(index != -1) {
                cnt++;
               swap(arr[i] , arr[index]); 
            }
        }
        return cnt;
    }
};
