#include <iostream>
using namespace std;

//Implementation
class node {
    public:
        int data;
        node *next;
        node() {
            next = nullptr;
        }
};

class LinkedList {
    node* head;
    public:
        LinkedList() {
            head = nullptr;
        }
        void insertNodeatHead(int element);
        void insertNodeatEnd(int element);
        void printList();
        int search(int key);
        void deleteatBeginning();
        void deleteatIndex(int index);
};



//Driver Code
int main() {
    LinkedList l;
    l.insertNodeatHead(5);
    l.insertNodeatHead(4);
    l.insertNodeatEnd(6);
    l.printList();
    l.insertNodeatEnd(1);
    l.printList();
    l.deleteatIndex(3);
    l.printList();
    cout << l.search(5)<<endl;
}



void LinkedList :: insertNodeatHead(int element) {
    node *temp = new node();
    temp->data = element;
    temp->next = head;
    head = temp;
}
void LinkedList :: insertNodeatEnd(int element) {
    node *temp = new node();
    temp->data = element;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
        return;
    }
    node *last = head;
    while(last->next != nullptr) {
        last = last->next;
    }
    last->next = temp;
}
void LinkedList :: printList() {
    if (head == nullptr) {
        cout << "Empty List" << '\n';
        return;
    }
    node *pos = head;
    while(pos != nullptr) {
        cout << pos->data << ' ';
        pos = pos->next;
    }
    cout << "\n";
}
int LinkedList :: search(int key) {
    /*      RETURN VALUES
        -2 = Empty List
        -1 = Not Found
        Non-Negative Integer = Index
    */
    if (head == nullptr) return -2;
    int pass = 0;
    int index = -1;
    node *temp = head;
    while (temp != nullptr) {
        index++;
        if (temp->data == key) {
            pass = 1;
            break;
        }
        temp = temp->next;
    }
    if (pass == 0) return -1;
    else if (pass == 1) return index;
}
void LinkedList :: deleteatBeginning() {
    if (head == nullptr) return;
    node* temp = head;
    head = head->next;
    free(temp);
}
void LinkedList :: deleteatIndex(int index) {
    // -2 if empty list
    if (head == nullptr) return;
    if (index == 0) {
        deleteatBeginning();
        return;
    }
    node* start = head;
    int t = index -1;
    while(t--) {
        if (start->next->next == nullptr) {
            // -1 if not found
            return;
        }
        start = start->next;
    }
    node* temp = start->next;
    start->next = start->next->next;
    free(temp);
}