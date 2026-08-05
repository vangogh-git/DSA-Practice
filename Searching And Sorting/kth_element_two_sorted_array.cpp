// optimized solution
// time complexity : O(log(min(n,m)))
// space complexity : O(1)


class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        
        int n = a.size();
        int m = b.size();
        
        if(n > m) {
            return kthElement(b , a , k);
        } 
        
        int low = max(0,k-m) , high = min(k , n);
        
        
        while(low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : a[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : b[cut2-1];
            int r1 = cut1 == n ? INT_MAX : a[cut1];
            int r2 = cut2 == m ? INT_MAX : b[cut2];
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1,l2);
            }
            
            else if(l1 > r2) {
                high = cut1 - 1;
            }
            
            else {
                low = cut1 + 1;
            }
        }
        
        return -1;
    }
};


// time complexity : O(n+m log n+m)
// space complexity : O(1)

class Solution {
    private: 
    int nextGap(int gap) {
        if(gap <= 1) return 0;
        return (gap/2) + (gap%2);
    }
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        
        int n = a.size();
        int m = b.size();
        
        int gap = nextGap(n + m);
        
        while(gap > 0) {
            int i = 0;
            int j = gap;
            
            while(j < n+m) {
                
                if(j < n) {
                    if(a[i] > a[j]) {
                        swap(a[i] , a[j]);
                    }
                }
                
                else if(i >= n) {
                    if(b[i-n] > b[j-n]) {
                        swap(b[i-n] , b[j-n]);
                    }
                }
                
                else {
                    if(a[i] > b[j-n]) {
                        swap(a[i] , b[j-n]);
                    }
                }
                i++;
                j++;
            }
            
            gap = nextGap(gap);
        }
        
        if(k <= n) return a[k-1];
        else return b[k-n-1];
        
    }
};

// approach 2:
// time complexity : O(n+m)
// space complexity : O(n+m)

int kthElement(vector<int> &a, vector<int> &b, int k) {
    int n = a.size();
    int m = b.size();
    
    vector<int> ans(n + m);
    int i = 0, j = 0, y = 0;

    while(i < n && j < m) {
        if(a[i] < b[j]) {
            ans[y++] = a[i++];
        } else {
            ans[y++] = b[j++];
        }
    }

    while(i < n) ans[y++] = a[i++];
    while(j < m) ans[y++] = b[j++];

    return ans[k - 1];
}
