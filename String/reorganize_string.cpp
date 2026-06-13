// Time Complexity : O(n*logn)
// Space Complexity : O(n)

// we use hashmap + max heap as max heap takes only log n time to complete

class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        // we need the frequency
        unordered_map<char, int> freq;
        for(char ch : s) {
            freq[ch]++;
        }

        // we need to create a max heap
        // a max heap pair is different from a normal non pair heap
        // here they will first check the char with the char 
        // so 'z' > 'b' > 'a' and then only the count will be checked
        // so we need to make the pair<int,char>
        priority_queue<pair<int,char>> max_heap;

        for(auto it : freq) {
            max_heap.push({it.second , it.first});
        }
 
        char prev = '#'; // anything not in string
        while(!max_heap.empty()) {
            auto maxi = max_heap.top();
            max_heap.pop();
            if(maxi.second == prev) {
                // if no other element in heap
                if(max_heap.empty()) {
                    return "";
                }
                //else
                auto sec_max = max_heap.top();
                max_heap.pop();

                ans += sec_max.second;
                prev = sec_max.second;
                sec_max.first--;
                if(sec_max.first > 0) {
                    max_heap.push(sec_max);
                }

                // finally we also add first wala 
                if(maxi.first > 0) max_heap.push(maxi);
                
            }
            else{
                ans += maxi.second;
                prev = maxi.second;
                maxi.first--;

                if(maxi.first > 0) {
                    max_heap.push(maxi);
                }    
            }
        }

        return ans;
    }
};
