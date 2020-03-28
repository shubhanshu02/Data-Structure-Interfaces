#include <iostream>
using namespace std;

//Implementation
class node {
    public:
        int data;
        node *next;
        
}*head;

//Interface
void insertNodeatHead(int element, node** head);
void insertNodeatEnd(int element, node** head);
void printList(node* head);
int search(node* head, int key);
void deleteatBeginning(node** head);
void deleteatIndex(node** head, int index);

//Driver Code
int main() {
    cout << "Welcome to Integer Linked List Interface!\n";
    while (true) {
        cout << "\nEnter the number indicated against the option you want to select.\n1. Insert a Node at the Head.\n2. Insert Node at the End\n3. Print the list\n";
        cout << "4. Search an element in the list\n5. Delete the Node at the Beginning\n6. Delete the node at a given index\n7. Exit\nInput: ";
        int input;
        cin >> input;
        int val;
        switch (input)
        {
        case 1:
            cout << "Enter the value of the integer you want to insert: ";
            cin >> val;
            insertNodeatHead(val, &head);
            break;
        case 2:
            cout << "Enter the value of the integer you want to insert: ";
            cin >> val;
            insertNodeatEnd(val, &head);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            cout << "Enter the value of the integer you want to search: ";
            cin >> val;
            search(head, val);
            break;
        case 5:
            deleteatBeginning(&head);
            break;
        case 6:
            cout << "Enter the index of the node you want to delete: ";
            cin >> val;
            deleteatIndex(&head, val);
            break;
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
}

//Definitions
void insertNodeatHead(int element, node** head) {
    node *temp = new node();
    temp->data = element;
    temp->next = *head;
    *head = temp;
}
void insertNodeatEnd(int element, node** head) {
    node *temp = new node();
    temp->data = element;
    temp->next = nullptr;
    if (*head == nullptr) {
        *head = temp;
        return;
    }
    node *last = *head;
    while(last->next != nullptr) {
        last = last->next;
    }
    last->next = temp;
}
void printList(node* head) {
    if (head == nullptr) {
        cout << "Empty List" << '\n';
        return;
    }
    node *pos = head;
    while(head != nullptr) {
        cout << head->data << '\n';
        head = head->next;
    }
}
int search(node* head, int key) {
    /*      RETURN VALUES
        -2 = Empty List
        -1 = Not Found
        Non-Negative Integer = Index
    */
    if (head == nullptr) {
        cout << "Empty List" << '\n';
        return -2;
    }
    int pass = 0;
    int index = -1;
    while (head != nullptr) {
        index++;
        if (head->data == key) {
            pass = 1;
            break;
        }
        head = head->next;
    }
    if (pass == 0) {
        cout << "NOT Found" << '\n';
        return -1;
    }
    else if (pass == 1) {
        cout << "Found " << key << " at index " << index << '\n';
        return index; 
    }
}
void deleteatBeginning(node** head) {
    if (*head == nullptr){
        cout << "Nothing to delete\n";
        return;
    }
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteatIndex(node** head, int index) {
    if (*head == nullptr) {
        cout << "Empty List. Can't Delete\n";
        return;
    }
    if (index == 0) {
        deleteatBeginning(head);
        return;
    }
    node* start = *head;
    int t = index -1;
    while(t--) {
        if (start->next->next == nullptr) {
            cout << "Index not found\n";
            return;
        }
        start = start->next;
    }
    node* temp = start->next;
    start->next = start->next->next;
    free(temp);
}