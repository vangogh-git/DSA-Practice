// t.c: O(n)
// s.c : O(n)

class Solution {
    private:
    int find(vector<int>& arr , int i) {
        if(i == arr.size()) {
            return -1;
        }
        else {
            return max(arr[i] , find(arr , i+1));
        }
    }
  public:
    int largest(vector<int> &arr) {
        
        return find(arr , 0);
        
    }
};
