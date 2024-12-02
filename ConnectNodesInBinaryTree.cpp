
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void dfs(Node* left) {
        if(left == nullptr) {
            return;
        }
        Node* cur = left;
        Node* lastRight = nullptr;
        left = nullptr;
        
        while(cur != nullptr) {
            if(cur->left != nullptr) {
                if(left == nullptr) {
                    left = cur->left;
                }
                if(lastRight != nullptr) {
                    lastRight->next = cur->left;
                }
                lastRight = cur->left;
            }
            if(cur->right != nullptr) {
                if(left == nullptr) {
                    left = cur->right;
                }
                if(lastRight != nullptr) {
                    lastRight->next = cur->right;
                }
                lastRight = cur->right;
            }
            cur = cur->next;
        }
        if(left) {
            dfs(left);
        }
    }
public:
    Node* connect(Node* root) {
        if(root == nullptr || (root->left == nullptr && !root->right)) {
            return root;
        }
        // dfs(root);
        // return root;
        Node *cur = root;
        while(cur) {
            Node* lastRight = nullptr;
            Node* leftestChild = nullptr;
            while(cur) {
                if(cur->left != nullptr) {
                    if(leftestChild == nullptr) {
                        leftestChild = cur->left;
                    }
                    if(lastRight != nullptr) {
                        lastRight->next = cur->left;
                    }
                    lastRight = cur->left;
                }
                if(cur->right != nullptr) {
                    if(leftestChild == nullptr) {
                        leftestChild = cur->right;
                    }
                    if(lastRight != nullptr) {
                        lastRight->next = cur->right;
                    }
                    lastRight = cur->right;
                }
                cur = cur->next;
            }
            cur = leftestChild;
        }
        return root;
    }
};
