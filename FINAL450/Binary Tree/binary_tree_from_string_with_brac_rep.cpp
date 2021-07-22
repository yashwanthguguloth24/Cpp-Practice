// https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
// https://www.youtube.com/watch?v=fx7TsehpSJo


// using recursion dividing into smaller problems

#include<iostream>
using namespace std;

// recursive code to solve the subproblems
class Node
{
    public:
        int data;
        Node* right;
        Node* left;
    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};


class StringToTree
{
    public:
        string inp;
    StringToTree(string s)
    {
        inp = s;
    }

    Node* GenerateTree(string inp)
    {
        if(inp == " " || inp.length() == 0)
        {
            return NULL;
        }
        int num = 0;
        int rootPtr = 0;
        // cout << "rootPtr : " << rootPtr << endl;
        while(rootPtr < inp.length() && inp[rootPtr] != '(' && inp[rootPtr] != ')')
        {
            // cout << "entered" << endl;
            num = num*10 + (int)(inp[rootPtr]-'0');
            rootPtr++;
        }

        Node* root = new Node(num);

        if(rootPtr > inp.length())
        {
            return root;
        }        

        int leftStart = rootPtr+1;
        int leftEnd = leftStart;
        if(leftStart < inp.length())
        {
            int open_cnt = 1;
            int close_cnt = 0;
            while(open_cnt != close_cnt)
            {
                if(inp[leftEnd] == '(')
                {
                    open_cnt++;
                }
                else if(inp[leftEnd] == ')')
                {
                    close_cnt++;
                }
                leftEnd++;
            }
            int len = (leftEnd-2)-leftStart+1;
            cout << inp.substr(leftStart,len) << endl;
            root->left = GenerateTree(inp.substr(leftStart,len));
        }

        if(leftEnd < inp.length())
        {
            int l = (inp.length()-2)-(leftEnd+1)+1;
            cout << inp.substr(leftEnd+1,l) << endl;
            root->right = GenerateTree(inp.substr(leftEnd+1,l));
        }
        return root;
    }

    void preOrder(Node* node)
    {
        if(node == NULL) return ;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }



};




int main()
{
    string s = "4(2(3)(1))(6(5))";
    // string s = "4()(6(5))";
    StringToTree stt = StringToTree(s);
    stt.preOrder(stt.GenerateTree(s));
    return 0;
}
