// Time Complexity: O(n logn)
// Space Complexity: O(n)


class Solution {
    private:
    void merge(vector<int>& arr, int l, int r , int mid) {
        int i=l;
        int j=mid+1;

        
        vector<int> temp;
        
        while(i<mid+1 && j<=r) {
            if(arr[i] < arr[j]) {
                temp.push_back(arr[i++]);
            }
            
            else {
                temp.push_back(arr[j++]);
            }
        }
        
        while(i < mid+1) {
            temp.push_back(arr[i++]);
        }
        
        while(j <= r){
            temp.push_back(arr[j++]);
        }
        
        for(int i=0 ; i<temp.size() ; i++) {
            arr[l+i] = temp[i];
        }
    }
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l >= r){
            return ;
        }
        
        else{
            int mid = l + (r-l)/2;
            
            mergeSort(arr , l , mid);
            mergeSort(arr , mid+1 , r);
            merge(arr , l , r , mid);
            
            
        }
    }
};
