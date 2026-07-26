// Time Complexity: O(n^2)
// Space Complexity : O(n) // because of stack used in recursion
// quickSort + Dutch National Flag Algorithm

#include <bits/stdc++.h> 
using namespace std;

pair<int,int> partition(vector<int>& arr , int beg , int end) {
    int lower = beg;
    int greater = end;
    int pivot = arr[beg];
    int i= beg;
    while(i <= greater) {
        if(arr[i] == pivot) {
            i++;
        }
        else if(arr[i] > pivot) {
            swap(arr[i] , arr[greater]);
            greater--;        
        }
        else  {
            swap(arr[i] , arr[lower]);
            lower++;
            i++;
        }
    }
    return {lower,greater};
}

void quickSort(vector<int> &arr , int beg , int end) {
    // base case
    if(beg < end) {
        pair<int,int> p = partition(arr , beg , end);
        int lower = p.first;
        int greater = p.second;

        quickSort(arr , beg , lower-1);
        quickSort(arr , greater+1 , end);
    }
}

vector<int> sortArray(vector<int> &arr)
{
    int n = arr.size();
    quickSort(arr , 0 , n-1);
    return arr;
}
