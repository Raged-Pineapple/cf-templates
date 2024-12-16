//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/
/*Approach:-
1.    first write a function to merge 2 lists,given that the lists are in sorted order
    keep a dummy node,let res=dNode,compare list1->data and list2->data values,
    point res to the smaller one,then assign that as res,in the end if any remainign elements,then connec them to res
2.  write a recursive function starting from head,treaverse deeper and deeper using temp->next;and 
the base case shall be till the last node is reached that is temp->next==NULL,each time call the merge2 funciton,
and merge the current head and head->next effectively
TC = O(2*nm)
SC = O(n)
*/
class Solution {
public:
    // Merge two sorted lists
    Node* merge2(Node* list1, Node* list2) {
        Node* dNode = new Node(-1); // Dummy node
        Node* res = dNode;

        // Merge two sorted linked lists
        while (list1 != NULL && list2 != NULL) {
            if (list1->data < list2->data) {
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            } else {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom; // Fixed bug here
            }
            res->next = NULL; // Set 'next' to NULL
        }

        // Attach the remaining elements of list1 or list2
        if (list1)
            res->bottom = list1;
        else
            res->bottom = list2;

        Node* result = dNode->bottom; // Get the head of the merged list
        delete dNode;                 // Free the dummy node
        return result;
    }

    Node* flatten(Node* root) {
        // Base case: if the list is empty or has only one list
        if (root == NULL || root->next == NULL) {
            return root;
        }

        // Recursively flatten the remaining list
        root->next = flatten(root->next);

        // Merge the current list with the flattened next list
        root = merge2(root, root->next);

        return root;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends
