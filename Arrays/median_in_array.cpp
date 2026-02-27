// Approach 1: Using MergeSort (Can be optimised Further)
// Time Complexity: O(nlogn)
// Space Complexity:O(n)


class Solution {
    private:
    void merge(int low , int high , int mid , vector<int> &arr) {
        int left = low;
        int right = mid+1;
        
        vector<int> temp;
        
        while(left <= mid && right <= high) {
            if(arr[left] < arr[right]) {
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
            }
        }
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        
        while(right <= high){
            temp.push_back(arr[right++]);
        }
            
        for(int i=low ; i<=high ; i++) {
            arr[i] = temp[i-low];
        }
    }
    
    void mergeSort(int low , int high , vector<int> &arr) {
        if(low >= high) {
            return ;
        }

            int mid = low + (high - low)/2;
            
            mergeSort(low , mid , arr);
            mergeSort(mid+1 , high , arr);
            merge(low , high , mid , arr);

    }
  public:
    double findMedian(vector<int> &arr) {
        int n = arr.size();
    mergeSort(0 , n - 1 , arr);

    if (n % 2 == 1) {
        return arr[n / 2];
    } else {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;  // NO 2.0
    }
    
    }
};
