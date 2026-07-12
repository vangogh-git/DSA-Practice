// time complexity : O(nlogn)
// space complexity : O(1)
// used binary search here 

class Solution {
    private:
    bool binarySearch(int target , vector<int> &arr , int beg , int end) {
        
        while(beg <= end) {
            int mid = beg + (end - beg)/2;
            
            if(arr[mid] == target) {
                return true;
            }
            else if(arr[mid] < target) {
                beg = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return false;
    }
  public:
    bool findPair(vector<int> &arr, int x) {
        int n = arr.size();
        
        sort(arr.begin() , arr.end());
        
        for(int i=0 ; i<n ; i++) {
            int target = arr[i] + x;
            bool ans = binarySearch(target , arr, i+1 , n-1);
            if(ans == true) return true;
        }
        
        return false;
    }
};



// using two pointer approach -> cleaner and better code
// time complexity : O(nlogn)
// space complexity : O(1)

class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        
        int n = arr.size();
        
        sort(arr.begin() , arr.end());
        
        int i = 0 , j = 1;
        
        while( i < n && j < n) {
            if(i != j && arr[j]-arr[i] == x) return true;
            else if(arr[j]-arr[i] < x) j++;
            else i++;
        }
        return false;
    }
};

