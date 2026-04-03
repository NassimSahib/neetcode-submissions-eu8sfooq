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
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        Node* start = node;
        set<Node*> visited;
        visited.insert(start);
        map<Node*, Node*> old_to_new;
        old_to_new[start] = new Node(start->val);
        stack<Node*> s_;
        s_.push(start);

        while (!s_.empty()) {
            Node* node_ = s_.top();
            s_.pop();
            
            for (Node* nei: node_->neighbors) {
                if (!visited.contains(nei)) {
                    visited.insert(nei);
                    old_to_new[nei] = new Node(nei->val);
                    s_.push(nei);
                }
            }
        }

        for (const auto& [old_node,new_node]: old_to_new) {
            for (auto nei: old_node->neighbors) {
                Node* new_nei = old_to_new[nei];
                new_node->neighbors.push_back(new_nei);
            }
        }
        return old_to_new[start];

        


        
    }
};
