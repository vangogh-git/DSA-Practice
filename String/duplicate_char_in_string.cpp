#include <bits/stdc++.h> 
vector<pair<char,int>> duplicate_char(string s, int n){
    // Write your code here.

    // first sort the string
    sort(s.begin() , s.end());

    vector<pair<char,int>> answer;
    int cnt = 1;
    // now store the count for each duplicated character
    for(int i=1 ; i<n ; i++) {
        
        if(s[i-1] == s[i]) {
            
            cnt++;
        }
        else{
            if(cnt > 1) {
                answer.push_back(make_pair(s[i-1] , cnt));
            }
            cnt = 1;
        }
    }

    if(cnt > 1) {
        answer.push_back({s[n-1], cnt});
    }

    return answer;
}
