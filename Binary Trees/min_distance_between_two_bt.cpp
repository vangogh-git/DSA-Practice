// t.c : O(n)
// s.c : O(h)

/* A binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
    int minDis = 0;
    private:
    int solve(Node* root , int a , int b) {
        if(root == NULL) return 0;
        else {
            int left = solve(root->left , a ,b);
            int right = solve(root->right , a, b);
            
            if(left && right) {
                minDis = left+right;
                return 0;
            }
            else if(root->data == a || root->data == b) {
                if(left || right) {
                    minDis = max(left,right);
                    return 0;
                }
                else {
                    return 1;
                }
            }
            else if(left || right) {
                return max(left,right)+1;
            }
            else {
                return 0;
            }
        }
    }
  public:
    int findDist(Node* root, int a, int b) {
        if(a == b) {
            return 0;
        }
        int temp = solve(root,a,b);
        return minDis;
    }
};
