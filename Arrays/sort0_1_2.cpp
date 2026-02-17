// Approach 1: Using basic count variable
// time complexity: O(n)
// space complexity: O(1)


void sort012(int arr[], int n) {
    int zero_cnt = 0;
    int one_cnt = 0;
    int two_cnt = 0;
    for(int i=0 ; i<n ; i++) {
        if(arr[i] == 0) {
            zero_cnt ++;
        }
        else if(arr[i] == 1) {
            one_cnt ++;
        }   
        else{
            two_cnt ++;
        }
    }
    for(int i=0 ; i<zero_cnt ; i++) {
        arr[i] = 0;
    }
    for(int i=zero_cnt; i<one_cnt + zero_cnt ; i++) {
        arr[i] = 1;
    }
    for(int i=one_cnt + zero_cnt ; i<n ; i++) {
        arr[i] = 2;
    }
}

// Approach 2 : Using Dutch National Flag Algorithm
// time comeplexty: O(n)
// space complexity: O(1)

void sort012(int arr[], int n) {
  
    int low = 0;
    int mid = 0;
    int high = n-1;
    int temp;
  
    while(mid <= high) {
      
        if(arr[mid] == 0) {
            temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            low++;
            mid++;
        }
          
        else if(arr[mid] == 1) {
            mid++;
        }
          
        else{
            // if arr[mid] == 2
            temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
      
    }   
}


