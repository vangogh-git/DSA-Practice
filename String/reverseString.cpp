// Time Complexity: O(n)
// Space Complexity: O(1)
// Two Pointer Approach


class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;

        while(i <= j) {
            swap(s[i] , s[j]);
            i++;
            j--;
        }
    }
};
