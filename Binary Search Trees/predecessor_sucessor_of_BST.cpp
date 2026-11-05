// t.c : O(n)
// s.c : O(n)
// brute force approach

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  private:
  void inorder(Node* root , vector<int> &arr) {
      if(root == nullptr) {
          return ;
      }
      
      inorder(root->left,arr);
      arr.push_back(root->data);
      inorder(root->right,arr);
  }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<int> arr;
        inorder(root,arr);
        
        int n = arr.size();
        int pre = -1;
        int suc = -1;
        
        for(int i=0 ; i<arr.size() ; i++) {
            if(arr[i] < key) {
                pre = arr[i];
            }
            else {
                if(arr[i] == key) {
                    if(i == n-1) {
                        suc = -1;
                        break;
                    }
                    suc = arr[i+1];
                    break;
                }
                else {
                    suc = arr[i];
                    break; 
                }
            }
        }
        
        vector<Node*> ans;
        if(pre == -1) ans.push_back(NULL);
        else ans.push_back(new Node(pre));
        if(suc == -1) ans.push_back(NULL);
        else ans.push_back(new Node(suc));
        
        return ans;
    }
};
