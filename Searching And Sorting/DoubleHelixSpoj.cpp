// t.c : O(n+m)
// s.c : O(1)
// simple two pointer approach

#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n1;
        cin >> n1;
        if (n1 == 0) break;

        int A[n1];
        for (int i = 0; i < n1; i++) cin >> A[i];

        int n2;
        cin >> n2;
        int B[n2];
        for (int i = 0; i < n2; i++) cin >> B[i];

        int i = 0, j = 0;
        long long sum1 = 0, sum2 = 0, result = 0;

        while (i < n1 && j < n2) {
            if (A[i] < B[j]) {
                sum1 += A[i++];
            } else if (A[i] > B[j]) {
                sum2 += B[j++];
            } else {
                result += max(sum1, sum2) + A[i];
                sum1 = sum2 = 0;
                i++;
                j++;
            }
        }

        while (i < n1) sum1 += A[i++];
        while (j < n2) sum2 += B[j++];

        result += max(sum1, sum2);

        cout << result << endl;
    }

    return 0;
}
