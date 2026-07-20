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
