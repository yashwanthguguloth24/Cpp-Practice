// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#

// Tricky problem using pair to store both diameter and height for every node.Use all 3 possibilities to get answer

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    
    
    pair<int,int> CalcDiameter(Node* root)
    {
        // pair< height,diameter>
        if(root == NULL)
        {
            pair<int,int> a(0,0);
            return a;
        }
        pair<int,int> leftPos = CalcDiameter(root->left);
        pair<int,int> rightPos = CalcDiameter(root->right);
        
        int throughNode = 1+leftPos.first+rightPos.first;
        
        pair<int,int> res;
        res.first = 1+max(leftPos.first,rightPos.first);
        res.second = max(throughNode,max(leftPos.second,rightPos.second));
        return res;
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // 1.can pass through root
        // 2.can be left
        // 3.can be right
        pair<int,int> ans = CalcDiameter(root);
        return ans.second;
        
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends
