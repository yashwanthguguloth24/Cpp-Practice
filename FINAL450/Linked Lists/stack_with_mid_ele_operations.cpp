// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

// Used linked list to design a stack with given operations.

#include<iostream>
using namespace std;

class DLL
{
    public:
        int data;
        DLL* next = NULL;
        DLL* prev = NULL;
        DLL(int a)
        {
            data = a;
        }
};

class Stack
{
    public:
        DLL* stack_head = NULL;
        DLL* stack_tail = NULL;
        DLL* stack_mid = NULL;
        int size = 0;
        void printLL()
        {
            DLL * temp = stack_head;
            while(temp != NULL)
            {
                cout << temp-> data << " ";
                temp = temp->next;
            }
            cout << endl;
        }



        void Push(int x)
        {
            DLL* newNode = new DLL(x);
            if(stack_head == NULL)
            {
                stack_head = newNode;
                stack_mid = newNode;
                size++;
            }
            else
            {
                newNode->next = stack_head;
                stack_head->prev = newNode;
                stack_head = newNode;
                size++;
                if(size%2 == 0)
                {
                    // cout << "called" << endl;
                    // cout << stack_mid->data << endl;
                    stack_mid = stack_mid->prev;
                    // cout << stack_mid->data << endl;
                }
            }

        }

        void Pop()
        {
            DLL* temp = stack_head;
            if(stack_head == stack_tail)
            {
                stack_head = stack_head->next;
                stack_tail = stack_tail->next;
                stack_mid = stack_mid->next;
                size--;

            }
            else
            {
                stack_head = stack_head->next;
                stack_head->prev = NULL;
                size--;
                if(size%2 != 0)
                {
                    stack_mid = stack_mid->next;
                }
            }
            temp->next = NULL;
            temp->prev = NULL;
        }

        int FindMiddleElement()
        {
            if(stack_mid == NULL)
            {
                return -1;
            }
            return stack_mid->data;
        }

        void DeleteMidElement()
        {
            if(size%2 != 0)
            {
                stack_mid->prev->next = stack_mid->next;
                stack_mid->next->prev = stack_mid->prev;
                stack_mid = stack_mid->prev;
            }
            else
            {
                stack_mid->prev->next = stack_mid->next;
                stack_mid->next->prev = stack_mid->prev;
                stack_mid = stack_mid->next;
            }
        }

};



// void printLL(DLL * head)
// {
//     DLL * temp = head;
//     while(temp != NULL)
//     {
//         cout << temp-> data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }



// void Push(DLL** stack_head,DLL **stack_tail,int x)
// {
//     DLL* newNode = new DLL(x);
//     if(*stack_head == NULL)
//     {
//         *stack_head = newNode;
//     }
//     else
//     {
//         newNode->next = *stack_head;
//         *stack_head = newNode;
//     }
// }

// void Pop(DLL** stack_head,DLL ** stack_tail)
// {
//     DLL* temp = *stack_head;
//     if(*stack_head == *stack_tail)
//     {
//         *stack_head = (*stack_head)->next;
//         *stack_tail = (*stack_tail)->next;

//     }
//     else
//     {
//         *stack_head = (*stack_head)->next;
//     }
//     temp->next = NULL;
//     temp->prev = NULL;
// }

// int FindMiddleElement


int main()
{
    Stack stk;
    stk.Push(100);
    stk.Push(20);
    stk.Push(30);
    stk.Push(40);
    stk.Push(50);
    stk.Push(60);
    stk.Push(70);
    stk.Push(90);
    stk.Push(110);
    stk.Push(130);
    stk.Push(140);
    stk.Push(150);
    stk.printLL();
    cout << stk.FindMiddleElement() << endl;
    stk.DeleteMidElement();
    stk.printLL();
    cout << stk.FindMiddleElement() << endl;    
    // stk.Pop();
    // stk.printLL();
    // cout << stk.size << endl;

    // DLL * stack_head = new DLL(1);
    // DLL * stack_tail = stack_head;
    // Push(&stack_head,&stack_tail,10);
    // printLL(stack_head);
    // Push(&stack_head,&stack_tail,20);
    // Push(&stack_head,&stack_tail,30);
    // Push(&stack_head,&stack_tail,40);
    // Push(&stack_head,&stack_tail,50);
    // printLL(stack_head);
    // Pop(&stack_head,&stack_tail);
    // printLL(stack_head);
    // Pop(&stack_head,&stack_tail);
    // printLL(stack_head);
    // Pop(&stack_head,&stack_tail);
    // printLL(stack_head);
    // Pop(&stack_head,&stack_tail);
    // printLL(stack_head);
    // Pop(&stack_head,&stack_tail);
    // printLL(stack_head);
    return 0;
}
