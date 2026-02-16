class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        
        // I am going to use max heap to solve this question
        priority_queue<int> pq;
        
        int n = arr.size();
        
        for(int i=0 ; i<k ; i++) {
            pq.push(arr[i]);
        }
        
        for(int i=k ; i<n ; i++) {
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        int ans = pq.top();
        return ans;
    }
};
