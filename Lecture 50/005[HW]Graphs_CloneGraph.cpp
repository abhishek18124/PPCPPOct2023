/*

https://leetcode.com/problems/clone-graph/

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
    Node* cloneGraph(Node* src) {

        if (!src) { // graph is empty
            return NULL;
        }

        unordered_map<Node*, Node*> cloneMap; // to store a mapping b/w nodes in the graph and their clones.
        queue<Node*> q; // to track vertices which have been cloned but the neighborList of the clone isn't populated.

        // create a clone of 'src'

        Node* srcClone = new Node(src->val);
        cloneMap[src] = srcClone;
        q.push(src);

        while (!q.empty()) {

            Node* front = q.front();
            q.pop();

            // fill the neighbourList of fronClone
            Node* frontClone = cloneMap[front];

            vector<Node*> neighbourList = front->neighbors;
            for (Node* neighbour : neighbourList) {
                if (cloneMap.find(neighbour) == cloneMap.end()) {
                    // neighbour is not yet cloned / visited
                    Node* neighbourClone = new Node(neighbour->val);
                    cloneMap[neighbour] = neighbourClone;
                    q.push(neighbour);
                }
                frontClone->neighbors.push_back(cloneMap[neighbour]);
            }

        }

        // return the clone of 'src'

        return srcClone; // return cloneMap[src]
    }
};