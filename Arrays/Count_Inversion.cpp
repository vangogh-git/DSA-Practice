


// Approach 1: Brute Force 
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        
        int n = arr.size();
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            int mini = arr[i];
            for(int j=i+1; j<n ; j++) {
                if(arr[j] < mini){
                    count++;
                }
            }
        }
        
        return count;
    }
};

// Approach 2: Using Merge Sort 
// Time Complexity : O(nlogn)
// Space Complexity : O(n)

class Solution {
    private:
    int merge(int low , int high , int mid , vector<int>& arr) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        
        int cnt = 0;
        
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
              // if that particular value is greater than arr[right] this would mean that every value on the right of the arr[left] will be greater than that value 
              // therefore we count the number of values to the right of arr[left] and return that value
                cnt += (mid - left + 1);
            }
        }
        
        while(left <= mid) {
            temp.push_back(arr[left++]);
        }
        
        while(right <= high) {
            temp.push_back(arr[right++]);
        }
        
        for(int i=low ; i<=high ; i++) {
            arr[i] = temp[i-low];
        }
        
        return cnt;
    }
    
    int mergeSort(int low , int high , vector<int>&arr) {
        
        if(low >= high) {
            return 0;
        }
        
            int mid = (high + low) / 2;
            int cnt=0;
            cnt += mergeSort(low , mid , arr);
            cnt += mergeSort(mid+1 , high , arr);
            cnt += merge(low , high , mid , arr);
            
            return cnt;

    }
  public:
    int inversionCount(vector<int> &arr) {
        
        return mergeSort(0 , arr.size()-1 , arr);
        
    }
};
