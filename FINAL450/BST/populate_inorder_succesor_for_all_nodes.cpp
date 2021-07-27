// https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#

// keep gloabal variable of prev node to change next pointer of prev node with curr node


class Solution
{
public:
    Node* prev = NULL;
    int cnt = 0;
    void populateNext(Node *root)
    {
        if(root == NULL)
        {
            return;
        }
        populateNext(root->left);
        if(cnt != 0)
        {
            prev->next = root;
            prev = root;
        }
        else
        {
            prev = root;
        }
        cnt++;
        populateNext(root->right);
    }
};
