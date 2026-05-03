//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution {
  public:
    void rearrange(vector<int> &arr) {
        
        int n = arr.size();
        
        vector<int> pos;
        vector<int> neg;
        
        for(int i=0 ; i<n ; i++) {
            if(arr[i] >= 0 ) {
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
      
        // now insert into arr the alternative way
        int i=0 , j=0 , k=0;
        int p = pos.size();
        int m = neg.size();
        
        while(i < p && j < m) {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }
        
        while(i < p) {
            arr[k++] = pos[i++];
        }
        
        while(j < m) {
            arr[k++] = neg[j++];
        }
        return ;
    }
};
