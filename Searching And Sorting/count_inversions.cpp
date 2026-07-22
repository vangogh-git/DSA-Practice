class Solution {
    private:
    void merge(vector<int> &arr , int beg , int mid , int end) {
        int i = beg;
        int j = mid+1;
        vector<int>temp(end-beg+1);
        int k=0;
        while(i <= mid && j <= end) {
            if(arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
            }
        }
        
        while(i<= mid) {
            temp[k++] = arr[i++];
        }
        while(j <= end) {
            temp[k++] = arr[j++];
        }
        
        // temp back to arr
        for(int i=beg ; i<= end ; i++) {
            arr[i] = temp[i-beg];
        }
    }
    void countInversion(vector<int> &arr , int beg , int mid , int end , int &cnt) {
        // so we visualize it with into having two arrays
        // first beg to mid and second mid+1 to end
        
        int i = mid;
        int j = end;
        while(i >= beg && j > mid) {
            if(arr[i] > arr[j]) {
                cnt += (j - mid);
                i--;
            }
            else {
                j--;
            }
        }
        
    }
    void mergeSort(vector<int> &arr , int beg , int end , int& cnt) {
        // base case
        if(beg >= end) {
            return ;
        }
        
        int mid = beg + (end - beg)/2;
        
        mergeSort(arr , beg , mid , cnt);
        mergeSort(arr , mid+1 , end , cnt);
        countInversion(arr , beg , mid , end , cnt);
        merge(arr , beg , mid , end);
        
    }
  public:
    int inversionCount(vector<int> &arr) {
        
        int n = arr.size();
        int cnt = 0;
        mergeSort(arr, 0 , n-1 ,cnt);
        
        return cnt;
    }
};
