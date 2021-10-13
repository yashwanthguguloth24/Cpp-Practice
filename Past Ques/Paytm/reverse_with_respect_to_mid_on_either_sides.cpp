#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* reverse(Node* root)
{
    Node* prev = NULL;
    Node* curr = root;
    while(curr)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int getLength(Node* root)
{
    int cnt = 0;
    while(root)
    {
        cnt++;
        root = root->next;
    }    
    return cnt;
}

Node* solve(Node* root)
{
    Node* head = root;
    Node* prev = NULL;
    Node* slow = root;
    Node* fast = root;
    int len = getLength(root);
    if(len%2 == 0)
    {
        while(fast && fast->next)
        {
            Node* temp1 = fast->next->next;
            Node* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
            fast = temp1;
        }
        head->next = reverse(slow);
        head = prev;
        return head;        
    }
    else
    {
        while(fast && fast->next)
        {
            Node* temp1 = fast->next->next;
            Node* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
            fast = temp1;
        }
        head->next = slow;
        head = slow;
        head->next = reverse(slow->next);
        head = prev;
        return head;
    }
}

void printLL(Node* root)
{
    while(root)
    {
        cout << root->data << " ";
        root = root->next;
    }
}


int main()
{
    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    root->next->next->next->next->next = new Node(6);
    root->next->next->next->next->next->next = new Node(7);
    root->next->next->next->next->next->next->next = new Node(8);
    root->next->next->next->next->next->next->next->next = new Node(9);
    Node* head = solve(root);
    printLL(head);

    return 0;
}
