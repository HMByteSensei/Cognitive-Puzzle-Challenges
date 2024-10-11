/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void dfs(Node* cur, std::vector<int> & rez) {
        for(auto next : cur->children) {
            dfs(next, rez);
            rez.push_back(next->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        if(!root) {
            return {};
        }
        std::vector<int> rez{};
        // dfs(root, rez);
        stack<Node*> sta;
        std::unordered_set<Node*> visited;
        sta.push(root);
        while(!sta.empty()) {
            Node* cur = sta.top();
            bool pushed = false;
            for(int i= cur->children.size()-1; i>=0; i--) {
                if(visited.count(cur->children[i]) == 0) {
                    visited.insert(cur->children[i]);
                    sta.push(cur->children[i]);
                    pushed = true;
                }
            }
            if(pushed == false) {
                rez.push_back(cur->val);
                sta.pop();
            }
        }
        return rez;
    }
};
