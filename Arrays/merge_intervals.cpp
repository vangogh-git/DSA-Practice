// Time Complexity: o(nlogn) + O(2*n)
// Space Complexity: O(n)
// Brute Force Approach

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        // first sort the array
        sort(intervals.begin() , intervals.end());

        int mini = 0 , maxi = 0;

        // now traverse thru array and see which pairs are overlapping
        for(int i=0 ; i<intervals.size() ; i++) {

            mini = intervals[i][0];
            maxi = intervals[i][1];
            // if we already put the pair under overlapping 
            // then just ignore that pair

            if(!ans.empty() && maxi <= ans.back()[1]) {
                continue;
            }
            for(int j=i+1 ; j<intervals.size() ; j++) {

                if(intervals[j][0] <= maxi && intervals[j][0] >= mini){
                    // lies in between the range
                    // it means overlapping so merge
                    maxi = max(maxi , intervals[j][1]);
                }

                else  {
                    break;
                }
            }

            ans.push_back({mini , maxi});

        }
       
       return ans;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
// Optimal Approach
// sorting the array first and then traversing in one go to get to the final answer

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        ans.push_back({start , end});

        for(int i=1 ; i<intervals.size() ; i++) {
            
            if(intervals[i][0] <= ans.back()[1] ) {
                end = max(end , intervals[i][1]);
                ans.back()[1] = end;
            }
            
            if(intervals[i][0] > ans.back()[1] ) {
                start = intervals[i][0];
                end = intervals[i][1];
                ans.push_back({start , end});
            }
        }
        
        return ans;
    }
};
