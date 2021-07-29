// https://www.geeksforgeeks.org/given-n-appointments-find-conflicting-appointments/
// https://www.geeksforgeeks.org/interval-tree/

// USING INTERVAL TREE to do insert and check operations in logn

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Interval
{
    public:
        int low;
        int high;
};


class ITNode
{
    public:
        Interval* itrvl;
        ITNode* left;
        ITNode* right;
        int max_val;
};

ITNode* newNode(Interval Itrvl)
{
    ITNode* temp = new ITNode;
    temp->itrvl = new Interval(Itrvl);
    temp->max_val = Itrvl.high;
    temp->left = temp->right = NULL;
}

ITNode* insert(ITNode *root,Interval Itrvl)
{
    if(root == NULL)
    {
        return newNode(Itrvl);
    }

    int l = root->itrvl->low;

    if(Itrvl.low < l)
    {
        root->left = insert(root->left,Itrvl);
    }
    else
    {
        root->right = insert(root->right,Itrvl);
    }

    if(root->max_val < Itrvl.high)
    {
        root->max_val = Itrvl.high;
    }

    return root;

}


bool isOverlap(Interval* i1,Interval i2)
{

    if(i1->low < i2.high && i1->high > i2.low)
    {
        return true;
    }
    return false;
}

Interval *searchOverlap(ITNode* root,Interval Itrvl)
{

    if(root == NULL)
    {
        return NULL;
    } 




    if(isOverlap(root->itrvl,Itrvl))
    {

        return (root->itrvl);
    }

    if(root->left != NULL && root->left->max_val >= Itrvl.low)
    {
        return searchOverlap(root->left,Itrvl);
    }
    return searchOverlap(root->right,Itrvl);
}

class Solution
{
    public:
        void printConflictingAppointments(Interval app[],int n)
        {
            ITNode* root = NULL;
            root = insert(root,app[0]);
            for(int i = 1;i<n;i++)
            {
                Interval* res = searchOverlap(root,app[i]);
                if(res != NULL)
                {
                    cout << "[" << app[i].low << "," << app[i].high
                 << "] Conflicts with [" << res->low << ","
                 << res->high << "]\n";
                }

                root = insert(root,app[i]);
            }

        }


};




int main()
{
    Interval appt[] = {{1, 5},{3, 7},{2, 6},{10, 15},{5, 6}, {4, 100}};
    int n = sizeof(appt)/sizeof(appt[0]);
    Solution a;
    a.printConflictingAppointments(appt,n);
    return 0;
}
