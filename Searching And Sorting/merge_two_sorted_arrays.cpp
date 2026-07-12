// time complexity : O(O((m+n)log(m+n)))
//space complexity : O(1)
// brute force approach


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m-1 , j=0;
        while(i >=0 && j < n) {
            if(nums2[j] < nums1[i]) {
                swap(nums1[i] , nums2[j]);
                i--;
                j++;
            }
            else {
                break;
            }
        }

        // sort the two arrays first
        sort(nums1.begin() , nums1.begin()+m);
        sort(nums2.begin() , nums2.end());

        for(int i=0 ; i<n ; i++) {
            nums1[m+i] = nums2[i];
        }
        return ;
    }
};


// time complexity : O(m+n)
// space complexity : O(1)
// optimized Solution

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = n+m;

        for(int i=0 ; i<n ; i++) {
            nums1[m+i] = nums2[i];
        }

        // apply gap method
        int gap = (len/2) + len%2;

        while(gap > 0) {
            int left = 0;
            int right = left + gap;

            while(right < len) {
                if(nums1[left] > nums1[right]) {
                    swap(nums1[left] , nums1[right]);
                }
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = (gap/2) + (gap%2);
        }
        return ;
    }
};

