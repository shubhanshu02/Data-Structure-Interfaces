#include <iostream>
using namespace std;

//Implementation
class node {
    public:
        int data;
        node *next;
        node() {
            data = 0;
            next = nullptr;
        }
};

class CircularLinkedList {
    node* head;
    public:
        CircularLinkedList() {
            head = nullptr;
        }
        void insertatHead(int val);
        void insertatEnd(int val);
        void deleteatHead();
        void deleteatEnd();
        void printList();
        int search(int val);
};

int main() {
    CircularLinkedList l;
    l.insertatEnd(5);
    l.printList();
    l.insertatEnd(4);
    l.printList();
    l.insertatEnd(3);
    l.insertatHead(0);
    l.printList();
    cout << l.search(3) << endl;
}

void CircularLinkedList :: insertatHead(int val) {
    node* temp = new node();
    temp->data = val;
    temp->next = head;
    if (head == nullptr) {
        head = temp;
        head->next = head;
    }
    else {
        node* traverse = head;
        while (traverse->next != head)
        {
            traverse = traverse->next;
        }
        head = temp;
        traverse->next = head;
    }
}

void CircularLinkedList :: insertatEnd(int val) {
    if (head == nullptr) return insertatHead(val);
    node* temp = new node();
    temp->data = val;
    temp->next = head;
    node* traverse = head;
    while (traverse->next != head)
    {
        traverse = traverse->next;
    }
    traverse->next = temp;
}

void CircularLinkedList :: deleteatHead() {
    if (head == nullptr) return;
    node* temp = head;
    node* traverse = head;
    while (traverse->next != head)
    {
        traverse = traverse->next;
    }
    head = head->next;
    traverse->next = head;
    free(temp);
}

void CircularLinkedList :: deleteatEnd() {
    if (head == nullptr) return;
    if (head->next == nullptr) return deleteatHead();
    node* traverse = head;
    while (traverse->next->next != head)
    {
        traverse = traverse->next;
    }
    node* temp = traverse->next;
    traverse->next = head;
    free(temp);
}

void CircularLinkedList :: printList() {
    if (head == nullptr) return;
    node* traverse = head;
    while (traverse->next != head)
    {
        cout << traverse->data << " ";
        traverse = traverse->next;
    }
    cout << traverse->data << " ";
    cout << endl;
}
int CircularLinkedList :: search(int val) {
    if (head == nullptr) return -2;
    node* traverse = head;
    int index = 0;
    if (head->data == val) return 0;
    while(traverse->next != head) {
        if (traverse->data == val) {
            return index;
        }
        index++;
        traverse = traverse->next;
    }
    if (traverse->data == val) return index;
    return -1;
}