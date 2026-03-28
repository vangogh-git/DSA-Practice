//Time Compplexity: O(n)
//Space Complexity: O(1)


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;
        
        int maxIndex = 0;
        int end = 0;
        int count = 0;
        
        for(int i = 0; i < n-1; i++) {
            
            if(i > maxIndex) {
                return -1;
            }
            
            maxIndex = max(maxIndex, i + arr[i]);
            
            if(i == end) {
                if(end == maxIndex) return -1;
                count++;
                end = maxIndex;
            }
        }
        
        return count;
    }
};
