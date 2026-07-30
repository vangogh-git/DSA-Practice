// time complexity : O(logp * p * l)
// space complexity : O(1)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool canWeCook(vector<int>& arr, long long mid, int p) {
    int total_prata = 0;

    for(int i = 0; i < arr.size(); i++) {
        int rank = arr[i];
        long long timespent = 0;
        int j = 1;

        while(true) {
            timespent += (long long)j * rank;

            if(timespent > mid) break;

            total_prata++;
            j++;

            if(total_prata >= p) return true;
        }
    }
    return false;
}

long long roti_prata(vector<int> &arr, int p, int l) {
    long long low = 0;

    int maxi = *max_element(arr.begin(), arr.end());

    long long high = (long long)maxi * (p * (p + 1) / 2);

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(canWeCook(arr, mid, p)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int p, l;
        cin >> p;

        cin >> l;
        vector<int> arr(l);

        for(int i = 0; i < l; i++) {
            cin >> arr[i];
        }

        cout << roti_prata(arr, p, l) << endl;
    }

    return 0;
}
