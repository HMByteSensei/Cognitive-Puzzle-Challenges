struct Tree {
    int val;
    Tree* left;
    Tree* right;
    int counter = 1;
    Tree(int v) : val(v), left(nullptr), right(nullptr) {}
};
class KthLargest {
private:
    int k;
    Tree* root = nullptr;
    Tree* searchK(int k, Tree* cur) {
        int R = (cur->right) ? cur->right->counter : 0;
        
        if(k == R + 1) {
            return cur;
        } else if(k <= R) {
            return this->searchK(k, cur->right);
        } else {
            return this->searchK(k - (R + 1), cur->left);
        }
    }
    
    int insert(int val) {
        if(!root) {
            root = new Tree(val);
            return val;
        }
        std::stack<Tree*> sta;
        Tree* cur = root;
        Tree *new_node = new Tree(val);
        while(cur) {
            sta.push(cur);
            if(cur->val > val) {
                cur = cur->left;
            } else if (cur->val < val) {
                cur = cur->right;
            } else {
                new_node->right = cur->right;
                cur->right = new_node;
                if(new_node->right) {
                    new_node->counter = new_node->right->counter + 1;
                }
                break;
            }
        }
        if(!cur) {
            Tree* prev = sta.top();
            if(prev->val > val) {
                prev->left = new_node;
            } else {
                prev->right = new_node;
            }
        }
        while(!sta.empty()) {
            sta.top()->counter++;
            sta.pop();
        }
        return 0;
    }
public:
    // Constructor
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for(int num : nums) {
            this->insert(num);
        }
    }
    int add(int val) {
        this->insert(val);
        return this->searchK(k, root)->val;
    }
    
};
