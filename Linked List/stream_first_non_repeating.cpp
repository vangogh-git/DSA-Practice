// time complexity:  O(n)
// space complexity : O(1) // only 26 constant spaces required hence O(1)
// here we make use of two arrays and a linked list to make sure we get the first non repeating character correctly

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        
        Node(int data) {
            this -> data = data;
            this  -> next = NULL;
            this -> prev = NULL;
        }
};

class Solution {
    private:
    void deleteFromList(Node* &curr , Node* &temp) {
        
        if(curr->next != NULL) {
            curr -> next -> prev = curr -> prev;
            curr -> prev -> next = curr -> next;
        }
        else {
            curr -> prev -> next = NULL;
            temp = curr -> prev;
        }
        
        curr = NULL;
    }
  public:
    string firstNonRepeating(string &s) {
        
        string ans = "";
        
        vector<Node*> address(26);
        vector<bool> repeated(26);
        
        for(int i=0 ; i<26 ; i++) {
            address[i] = NULL;
        }
        
        Node* head = new Node(-1);
        Node* temp = head;
        
        for(int i=0 ; i<s.size() ; i++) {
            
            int index = s[i] - 'a';
            if(repeated[index] == true) {
                // do nothing
            }
            else if(address[index] != NULL) {
                repeated[index] = true;
                deleteFromList(address[index] , temp);
            }
            else {
                Node* character = new Node(s[i]);
                temp -> next = character;
                character -> prev = temp;
                temp = temp -> next;
                address[index] = character;
            }
            if(head -> next != NULL) 
                ans += head -> next -> data;
            else 
                ans += '#';
        }
        
        return ans;
    }
};
