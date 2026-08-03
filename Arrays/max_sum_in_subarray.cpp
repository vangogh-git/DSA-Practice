// Using KADANE'S ALGORITHM
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int sum = 0;
        int maxi = arr[0];
        
        for(int i=0 ; i<n ; i++) {
            sum += arr[i];
            maxi = max(maxi , sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        
        return maxi;
    }
};


// using divide and conquer approach
// t.c : O(nlogn)
// s.c : O(1)

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int CSS(vector<int> &arr , int l , int mid , int r , int &start , int &end) {
	int sum = 0;
	int leftSum = INT_MIN;
	int maxLeft = mid;
	
	for(int i=mid ; i>=l ; i--) {
		sum += arr[i];
		if(sum > leftSum) {
			leftSum = sum;
			maxLeft = i;
		}
	}
	
	sum = 0;
	int rightSum = INT_MIN;
	int maxRight = mid+1;
	
	for(int i = mid+1 ; i<=r ; i++) {
		sum += arr[i];
		if(sum > rightSum ) {
			rightSum = sum;
			maxRight = i;
		}
	}
	
	start = maxLeft;
	end = maxRight;
	
	return leftSum + rightSum;
}

int maxSubarray(vector<int>& arr , int l , int r , int &start , int &end) {
	if(l == r) {
		start = end = l;
		return arr[l];
	}
	
	int mid = (l+r)/2;
	
	int leftStart, leftEnd;
	int rightStart , rightEnd;
	int crossStart , crossEnd;
	
	int leftSum = maxSubarray(arr, l , mid , leftStart , leftEnd);
	int rightSum = maxSubarray(arr , mid+1 , r , rightStart , rightEnd);
	int crossSum = CSS(arr , l , mid , r , crossStart , crossEnd);
	
	if(leftSum >= rightSum && leftSum >= crossSum) {
		start = leftStart;
		end = leftEnd;
		return leftSum;
	}
	
	else if (rightSum >= leftSum && rightSum >= crossSum) {
        start = rightStart;
        end = rightEnd;
        return rightSum;
    }
    
    else {
    	start = crossStart;
    	end = crossEnd;
    	return crossSum;
	}
}

int main() {
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i=0 ; i<n; i++) {
		cin >> arr[i];
	}
	
	int start , end;
	int ans = maxSubarray(arr , 0 , n-1 , start , end);
	
	cout << "Maximum Subarray Sum : " << ans << endl;
	cout << "Maximum Subarray: ";
	for(int i=start ; i<= end ; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	
	return 0;
}
