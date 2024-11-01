/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* dfs(Node* cur, std::unordered_set<Node*> &visited, std::unordered_map<Node*, Node*> &mapa) {
        Node *novi = new Node(cur->val);
        mapa.insert({cur, novi});

        for(Node* next : cur->neighbors) {
            if(visited.insert(next).second) {
                Node *tmp = dfs(next, visited, mapa);
                (novi->neighbors).push_back(tmp);
            } else {
                (novi->neighbors).push_back(mapa[next]);
            }
        }
        return novi;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }
        std::unordered_set<Node*> visited{};
        std::unordered_map<Node*, Node*> mapa{};

        visited.insert(node);
        return dfs(node, visited, mapa);
    }
};
