// https://leetcode.com/problems/clone-graph/

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
        vector<bool> visited(101);
        vector<Node*> myNode(101);
        if(node == NULL)
        {
            return NULL;
        }
        Node* source = new Node(node->val);
        queue<pair<Node*,Node*>> q;
        q.push(make_pair(node,source));
        myNode[node->val] = source;
        visited[node->val] = true;
        while(!q.empty())
        {
            pair<Node*,Node*> temp = q.front();
            q.pop();
            
            Node* given = temp.first;
            Node* mine = temp.second;

            
            for(int i = 0;i<(given->neighbors).size();i++)
            {
                if(visited[(given->neighbors)[i]->val] == false)
                {
                    Node* neighbs = new Node((given->neighbors)[i]->val);
                    (mine->neighbors).push_back((neighbs));
                    q.push(make_pair((given->neighbors)[i],neighbs));
                    visited[(given->neighbors)[i]->val] = true;
                    myNode[neighbs->val] = neighbs;
                 }
                else
                {
                    (mine->neighbors).push_back(myNode[(given->neighbors)[i]->val]);
                }

            }
        }
        return source;
    }
};
