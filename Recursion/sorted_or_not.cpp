// t.c : O(n)
// s.c : O(n) because of recursion call stack

class Solution {
    private:
    bool checkSorted(vector<int>& arr , int first) {
        if(first+1 == arr.size()) {
            return true;
        }
        else {
            if(arr[first] > arr[first+1]) {
                return false;
            }
            else {
                checkSorted(arr , first+1);
            }
        }
    }
  public:
    bool isSorted(vector<int>& arr) {
        
        bool check = checkSorted(arr , 0);
        return check;
    }
};
