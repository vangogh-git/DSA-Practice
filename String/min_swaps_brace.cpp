// Time Compelxity : O(n)
// Space Complexity : O(1)

class Solution {
  public:
    int minimumNumberOfSwaps(string& s) {
        
        int countLeft = 0;
        int countRight = 0;
        int imbalance = 0;
        int swaps = 0;
        
        for(char ch : s) {
            if(ch == '[') {
                countLeft++;
                
                if(imbalance > 0) {
                    swaps += imbalance;
                    imbalance--;
                }
            }
            else {
                countRight++;
                imbalance = countRight - countLeft;
            }
        }
        
        return swaps;
        
    }
};
