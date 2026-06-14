// Time Complexity : O(n*logn)
// Space Complexity : O(n)

// we use hashmap + max heap as max heap takes only log n time to complete
// this code also gives an idea of how pair works in a priority queue 
// and how we can make a custom comparator...

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


// using CUSTOM COMPARATOR
///////////////////////////

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
        
        auto cmp = [](pair<char,int>a , pair<char,int>b){
            return a.second < b.second;
        };
        priority_queue<pair<char,int> , vector<pair<char,int>> , decltype(cmp)> max_heap(cmp);

        for(auto it : freq) {
            max_heap.push({it.first , it.second});
        }
 
        char prev = '#'; // anything not in string
        while(!max_heap.empty()) {
            auto maxi = max_heap.top();
            max_heap.pop();
            if(maxi.first == prev) {
                // if no other element in heap
                if(max_heap.empty()) {
                    return "";
                }
                //else
                auto sec_max = max_heap.top();
                max_heap.pop();

                ans += sec_max.first;
                prev = sec_max.first;
                sec_max.second--;
                if(sec_max.second > 0) {
                    max_heap.push(sec_max);
                }

                // finally we also add first wala 
                if(maxi.first > 0) max_heap.push(maxi);
                
            }
            else{
                ans += maxi.first;
                prev = maxi.first;
                maxi.second--;

                if(maxi.second > 0) {
                    max_heap.push(maxi);
                }    
            }
        }

        return ans;
    }
};

//////////////////////////////////
