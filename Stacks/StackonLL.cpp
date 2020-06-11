#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node *next;
        node() {
            data = 0;
            next = nullptr;
        }
};

class LinkedList {
    node* head;
    public:
        int size;
        LinkedList() {
            head = nullptr;
            size = 0;
        }
        void insertNodeatHead(int element);
        void insertNodeatEnd(int element);
        void printList();
        int search(int key);
        void deleteatBeginning();
        void deleteatIndex(int index);
        int getTop();
};

class StackLL {
    LinkedList s;
    public:
        void push(int val);
        int pop();
        int size();
        int isEmpty();
        int peek();
};

int main() {
    StackLL s;
    s.push(5);
    cout << s.peek() << endl;
    s.push(3);
    s.push(600);
    s.pop();
    cout << s.peek() << endl;
}


void StackLL :: push(int val) {
    s.insertNodeatHead(val);
}
int StackLL :: pop() {
    int value = s.getTop();
    s.deleteatBeginning();
    return value;
}
int StackLL :: size() {
    return s.size;
}
int StackLL :: isEmpty() {
    return size()?0:1;
}
int StackLL :: peek() {
    return s.getTop();
}
void LinkedList :: insertNodeatHead(int element) {
    node *temp = new node();
    temp->data = element;
    temp->next = head;
    head = temp;
    size++;
}
void LinkedList :: insertNodeatEnd(int element) {
    node *temp = new node();
    temp->data = element;
    temp->next = nullptr;
    size++;
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
    size--;
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
    size--;
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
int LinkedList :: getTop() {
    return head->data;
}