class Solution {
  public:
    void reverseArray(vector<int> &arr) {  
        int n = arr.size();
       int temp;
       int i=0;
       int j=arr.size()-1;  
       while(i <= j) {
           temp = arr[j];
           arr[j] = arr[i];
           arr[i] = temp;   
           i++;
           j--;
       }
    }
};

