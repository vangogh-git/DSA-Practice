// Time Complexity: o(n^2)
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
