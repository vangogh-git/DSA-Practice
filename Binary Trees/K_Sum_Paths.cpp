// t.c : O(n)
// s.c : O(n) for using path vector

/* Structure of Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
    private:
    void solve(Node* root , int k , vector<int> &path, int &cnt) {
        if(root == NULL) {
            return ;
        }
        else {
            path.push_back(root->data);
            solve(root->left , k , path , cnt);
            solve(root->right , k , path , cnt);
            int sum = 0;
            for(int i=path.size()-1 ; i>=0 ; i--) {
                sum += path[i];
                if(sum == k) {
                    cnt++;
                }
            }
            path.pop_back();
        }
    }
  public:
    int countAllPaths(Node *root, int k) {
        
        vector<int> path;
        int cnt = 0;
        solve(root , k , path , cnt);
        return cnt;
        
    }
};
