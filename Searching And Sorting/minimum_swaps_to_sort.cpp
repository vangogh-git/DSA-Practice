// Brute Force Approach
// Time Complexity : O(n^2)
// Space Complexity : O(1)


class Solution {
  public:
    int minSwaps(vector<int>& arr) {
    
        int cnt = 0;
        for(int i=0 ; i<arr.size() ; i++) {
            int mini = arr[i];
            int index = -1;
            for(int j=i+1 ; j <arr.size() ; j++) {
                if(arr[j] < mini) {
                    mini = arr[j];
                    index = j;
                }
            }
            if(index != -1) {
                cnt++;
               swap(arr[i] , arr[index]); 
            }
        }
        return cnt;
    }
};

// Optimal Approach
// Time Complexity : O(nlogn)
// Space Complexity : O(n)


class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>>v;
        for(int i=0 ; i<n ; i++) {
            v.push_back({arr[i],i});
        }
        sort(v.begin() , v.end());
        int swap_cnt = 0;
        for (int i=0 ; i<arr.size() ; i++) {
            pair<int,int>p = v[i];
            int index = p.second;
            int value = p.first;
            
            if(i != index) {
                swap(v[i] , v[index]);
                swap_cnt++;
                i--;
            }
        }
        return swap_cnt;
    }
};
