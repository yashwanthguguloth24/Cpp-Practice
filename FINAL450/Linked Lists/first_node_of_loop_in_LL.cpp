// https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next = NULL;
};

Node * newNode(int key)
{
    Node * temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// *********METHOD 1 ****************
Node * DetectAndPointFirstNode1(Node * head)
{
    // Moving the second pointer  and first pointer with same pace to meet a start node of loop.
    struct Node * fast_ptr = head;
    struct Node * slow_ptr = head;
    while(fast_ptr->next != NULL && fast_ptr->next->next != NULL && slow_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
        if(fast_ptr == slow_ptr)
        {
            break;
        }
    }
    if(fast_ptr->next == NULL)
    {
        return NULL;
    }
    else
    {
        Node * first_ptr = head;
        while(first_ptr->next != fast_ptr->next)
        {
            fast_ptr = fast_ptr->next;
            first_ptr = first_ptr->next;
        }
        return fast_ptr->next;
    }
}

// *******METHOD 2******************
Node * DetectAndPointFirstNode2(Node * head)
{
    // point every node to temp pointer, if there loop we can detect it easily (temp node is flag here)
    Node * temp = new Node;
    Node * first_ptr = head;
    while(first_ptr != NULL)
    {
        if(first_ptr->next == NULL)
        {
            return NULL;
        }
        if(first_ptr->next == temp)
        {
            return first_ptr;
        }
        Node * nex = first_ptr->next;
        first_ptr->next = temp;
        first_ptr = nex;
    }
}



int main()
{
    /*
    Linked list created here:
    1 -> 2 -> 3 -> 4 -> 5
             |__________|
                        

    */
    Node* head = newNode(1);
    Node* tail = head;
    for(int i = 2;i<6;i++)
    {
        tail->next = newNode(i);
        tail = tail->next;
    }
    Node * temp = head;
    // loop at 3rd node
    for(int i = 0;i<2;i++)
    {
        temp = temp->next;
    }
    tail->next = temp;
    Node * out = DetectAndPointFirstNode1(head);
    cout << "USING METHOD1: "<< out->data << endl;
    Node* out1 = DetectAndPointFirstNode2(head);
    cout << "USING METHOD2: "<< out1->data << endl;    
    return 0;
}
