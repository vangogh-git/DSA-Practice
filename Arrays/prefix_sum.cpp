// very very basic question


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int l , r;
    cin >> l >> r;

    int arr[n];

    for(int i=0 ; i<n ; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for(int i=l ; i<r+1 ; i++) {
        sum += arr[i];
    }

    cout << sum << endl;
    return 0;
}
