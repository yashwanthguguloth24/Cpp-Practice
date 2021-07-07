// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// https://stackoverflow.com/questions/24672943/find-first-non-repeating-character-in-a-stream-of-characters
/*
Approach : using DLL to store the non repeating character nodes at every instant and using repeated array to see if any char is repeated.
Updating the string based on the head node of DLL.

repeated [] - This tells whether a character is repeated or not in a stream. We update this to TRUE when char is encountered twice.
inDLL[](array of pointers to characters) - We store the character pointers in array so that we can see if any char is already inserted in LL(if pointer is not NULL).
A DLL with head and tail pointers, head points to the first non-repeating character node.

*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	int MAX_CHAR = 256;
	struct node
    {
        char a;
        struct node *next, *prev;
    };

    // A utility function to append a character x at the end of DLL.
    // Note that the function may change head and tail pointers, that
    // is why pointers to these pointers are passed.
    void appendNode(struct node **head_ref, struct node **tail_ref, char x)
    {
        struct node *temp = new node;
        temp->a = x;
        temp->prev = temp->next = NULL;
    
        if (*head_ref == NULL)
        {
            *head_ref = *tail_ref = temp;
            return;
        }
        (*tail_ref)->next = temp;
        temp->prev = *tail_ref;
        *tail_ref = temp;
    }

    // A utility function to remove a node 'temp' fromt DLL. Note that the
    // function may change head and tail pointers, that is why pointers to
    // these pointers are passed.
    void removeNode(struct node **head_ref, struct node **tail_ref,struct node *temp)
    {
        if (*head_ref == NULL)
            return;
    
        if (*head_ref == temp)
            *head_ref = (*head_ref)->next;
        if (*tail_ref == temp)
            *tail_ref = (*tail_ref)->prev;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
    
        delete(temp);
    }
	
	
	
	
	
	
	
	string FirstNonRepeating(string A){
	    struct node *inDLL[MAX_CHAR];    
	    bool repeated[MAX_CHAR];

        // Initialize the above two arrays
        struct node *head = NULL, *tail = NULL;
        for (int i = 0; i < MAX_CHAR; i++)
        {
            inDLL[i] = NULL;
            repeated[i] = false;
        }
        string ans;
        // Let us consider following stream and see the process

        for (int i = 0; A[i]; i++)
        {
            char x = A[i];
            //cout << "Reading " << x << " from stream \n";
    
            // We process this character only if it has not occurred or occurred
            // only once. repeated[x] is true if x is repeated twice or more.s
            if (!repeated[x])
            {
                // If the character is not in DLL, then add this at the end of DLL.
                if (inDLL[x] == NULL)
                {
                    appendNode(&head, &tail, A[i]);
                    inDLL[x] = tail;
                }
                else // Otherwise remove this caharacter from DLL
                {
                    removeNode(&head, &tail, inDLL[x]);
                    inDLL[x] = NULL;
                    repeated[x] = true;  // Also mark it as repeated
                }
            }
    
            // Print the current first non-repeating character from stream
            if (head != NULL)
            {
                ans += head->a;
            }
            else
            {
                ans += "#";
            }
                
        }
        return ans;
	}
	

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
