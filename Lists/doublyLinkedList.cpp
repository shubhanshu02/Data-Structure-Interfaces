#include <iostream>
using namespace std;

//Implementation
class node {
    public:
        int data;
        node *next;
        node *prev;
        node() {
            data = 0;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    node* head;
    
    public:
node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }
        void insertNodeatHead(int element);
        void insertNodeatEnd(int element);
        void printList();
        int search(int key);
        void deleteatBeginning();
        void deleteatIndex(int index);
        void deleteatEnd();
};



//Driver Code
int main() {
    DoublyLinkedList l;
    l.insertNodeatHead(5);
    l.insertNodeatHead(4);
    l.insertNodeatEnd(6);
    l.printList();
    l.insertNodeatEnd(1);
    l.printList();
    l.deleteatIndex(2);
    l.printList();
    cout << l.search(5) << endl;
}



void DoublyLinkedList :: insertNodeatHead(int element) {
    node* temp = new node();
    temp->data = element;
    temp->next = head;
    head = temp;
    if (head->next != nullptr) {
        head->next->prev = head;
    }
    if (tail == nullptr) tail = temp;
}
void DoublyLinkedList :: insertNodeatEnd(int element) {
    node* temp = new node();
    tail->next = temp;
    temp->data = element;
    temp->prev = tail;
    tail = temp;
    if (head == nullptr) head = temp;
}
void DoublyLinkedList :: printList() {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int DoublyLinkedList :: search(int key) {
    node* traverse = head;
    if (head == nullptr) return -2;
    int index = 0;
    while (traverse != nullptr) {
        if (traverse->data == key) {
            return index;
        }
        traverse = traverse->next;
        index++;
    }
    return -1;
}
void DoublyLinkedList :: deleteatBeginning() {
    if (head == nullptr) {
        cout << "Underflow" << endl;
        return;
    }
    else if (head == tail) {
        node* temp = head;
        head = tail = nullptr;
        free(temp);
        return;
    }
    node* temp = head;
    head = head->next;
    head->prev = nullptr;
    free(temp);
}
void DoublyLinkedList :: deleteatEnd() {
    if (tail == nullptr) {
        cout << "Underflow" << endl;
        return;
    }
    else if (head == tail) {
        node* temp = head;
        head = tail = nullptr;
        free(temp);
        return;
    }
    node* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    free(temp);
}
void DoublyLinkedList :: deleteatIndex(int index) {
    if (index < 0) return;
    if (head == nullptr) return;
    node* traverse = head;
    if (index == 0) {
        deleteatBeginning();
        return;
    }
    while (traverse != nullptr && index != 0)
    {
        if (traverse->next == nullptr) break;
        traverse = traverse->next;
        index--;
    }
    if (index != 0) return;
    node* temp = traverse;
    if (traverse->prev != nullptr) traverse->prev->next = traverse->next;
    if (traverse->next != nullptr) traverse->next->prev = traverse->prev;
    free(temp);    
}
