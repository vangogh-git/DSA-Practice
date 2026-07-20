// time complexity : O(nlog n)
// space complexity : O(n)
// brute force approach

class Solution {
    private:
    int countOfBits(int num) {
        int cnt = 0;
        while(num) {
            cnt += (num&1);
            num >>= 1;
        }
        return cnt;
    }
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        
        vector<pair<int,int>> v;
        for(int i=0 ; i<arr.size() ; i++) {
            v.push_back({arr[i] , countOfBits(arr[i])});
        }
        
        // stable sort - comparator - lambda function
        stable_sort(v.begin() , v.end() , [](const pair<int,int>& a , const pair<int,int> &b){
            return a.second > b.second;
        });
        
        vector<int> ans;
        for(auto &p : v) {
            ans.push_back(p.first);
        }
        return ans;
    }
};

// time complexity : O(nlogn)
// space complexity : O(1)
// Note : this is the actual solution for this problem because it doesn't provide stable sort but indeed it is a clever approach.
class Solution {
    private:
    int countOfBits(int num) {
        int cnt = 0;
        while(num) {
            cnt += (num & 1);
            num >>= 1;
        }
        return cnt;
    }
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        int n = arr.size();
        int M = *max_element(arr.begin() , arr.end()) + 1;
        
        for(int i=0 ; i<n ; i++) {
            int bits = countOfBits(arr[i]);
            arr[i] += bits * M;
        }
        
        // sort
        sort(arr.begin(), arr.end(), greater<int>());
        
        // extract back
        for(int i=0 ; i<n ; i++) {
            arr[i] = arr[i] % M;
        }
        return arr;
    }
};

// optimized Solution
// time complexity: O(nlogn)
// space complexity: O(1)

class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        
        stable_sort(arr.begin() , arr.end() , [](int a , int b){
           return __builtin_popcount(a) > __builtin_popcount(b); 
        });
        return arr;
    }
};
