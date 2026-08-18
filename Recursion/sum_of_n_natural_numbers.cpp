// time complexity: O(n)
// space complexity: O(n)

#include <iostream>
using namespace std;

int Sum(int n) {
    if(n == 0) return 0;
    
    else {
        return n + Sum(n-1);
    }
}

int main() {
    int n;
    cin >> n;

    int sum = Sum(n);
    cout << sum;

    return 0;
}
