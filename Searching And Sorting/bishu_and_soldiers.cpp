// time complexity : O(NlogN) + O(QlogN)
// space complexity : O(N)
// pattern : binary search + prefix sum

#include <iostream>
#include <algorithm>
using namespace std;

int findCount(vector<int> &arr , int power) {
    int ans = -1;
    int low = 0;
    int high = arr.size()-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] <= power) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans+1;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) {
        cin >> arr[i];
    }

    sort(arr.begin() , arr.end());

    // create prefix sum array
    vector<int> prefix(N);
    prefix[0] = arr[0];
    for(int i=1; i<N ; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int power;
        cin >> power;

        int cnt = findCount(arr,power);
        // check the cnt
        int sum = 0;
        if(cnt > 0) {
            sum = prefix[cnt-1];
        }

        cout << cnt << " " << sum << endl;
    }

    return 0;
}

// can also use inbuilt upper_bound() function which uses binary search internally
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) {
        cin >> arr[i];
    }

    sort(arr.begin() , arr.end());

    // create prefix sum array
    vector<long long> prefix(N);
    prefix[0] = arr[0];
    for(int i=1; i<N ; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int power;
        cin >> power;

        int idx = upper_bound(arr.begin(),arr.end(),power) - 
        arr.begin();

        int count = idx;
        long long sum = (idx == 0) ? 0 : prefix[idx-1];

        cout << count << " " << sum << endl;
    }
    return 0;
}
