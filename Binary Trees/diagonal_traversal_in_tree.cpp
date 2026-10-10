// time complexity : O(nlogd) where d is the number of diagonals
// space complexity : O(n)

/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    private:
    void solve(Node* root , int pos , map<int,vector<int>> &mp) {
        if(root == NULL) {
            return ;
        }
        else {
            mp[pos].push_back(root->data);
            
            solve(root->left , pos+1 , mp);
            solve(root->right , pos , mp);
        }
    }
  public:
    vector<int> diagonal(Node *root) {
        
        map<int,vector<int>> mp;
        vector<int> ans;
        if(root == NULL) return ans;
        
        solve(root , 0 , mp);

        for(auto it: mp) {
            for(int val : it.second) {
                ans.push_back(val);
            }
        } 
        return ans;
    }
};


// t.c : O(n)
// s.c : O(n)

/* Structure of binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        
        map<int,vector<int>> mp;
        vector<int> ans;
        if(root == NULL) return ans;
        
        queue<pair<int,Node*>> q;
        q.push(make_pair(0,root));
        
        while(!q.empty()) {
            auto Front = q.front();
            q.pop();
            
            int pos = Front.first;
            Node* frontNode = Front.second;
            
            mp[pos].push_back(frontNode->data);
            
            if(frontNode -> left) {
                q.push({pos+1 , frontNode->left});
            }
            if(frontNode -> right) {
                q.push({pos , frontNode->right});
            }
        }
        for(auto it: mp) {
            for(int val : it.second) {
                ans.push_back(val);
            }
        } 
        return ans;
    }
};
