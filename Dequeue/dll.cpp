#include <iostream>
using namespace std;
#define size 50

class node {
    public:
        int data;
        node *next;
        node *prev;
        node() {
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        node* head;
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

class Dequeue {
    DoublyLinkedList list;
    public:
        Dequeue() {
            list = DoublyLinkedList();
        }
        bool is_empty();
        void push_front(int val);
        void push_back(int val);
        void pop_front();
        void pop_back();
        int get_front();
        int get_back();
};

int main() {
    int temp;
    Dequeue d;
    while (true)
    {
        cout << "\n1: is_empty\n" << "2: push_front\n" <<  "3: push_back\n" << "4: pop_front\n";
        cout << "5: pop_back\n" <<"6: get_front\n" << "7: get_back" << endl;
        cin >> temp;
        switch (temp)
        {
        case 1:
            cout << d.is_empty() << endl;
            break;
        case 2:
            int x;cin >> x;
            d.push_front(x);
            break;
        case 3:
            int t;cin >> t;
            d.push_back(x);
            break;
        case 4:
            d.pop_front();
            break;
        case 5:
            d.pop_back();
            break;
        case 6:
            cout << d.get_front()<< endl;
            break;
        case 7:
            cout << d.get_back()<< endl;
            break;
        default:
            cout <<"INVALID INPUT" << endl;
            break;
        }
    }
}

bool Dequeue :: is_empty() {
    if (list.head == nullptr) return true;
    else return false;
}
void Dequeue :: push_front(int val) {
    list.insertNodeatHead(val);
}
void Dequeue :: push_back(int val) {
    list.insertNodeatEnd(val);
}
void Dequeue :: pop_front() {
    list.deleteatBeginning();
}
void Dequeue :: pop_back() {
    list.deleteatEnd();
}
int Dequeue :: get_front() {
    if (is_empty()) return -1;
    else return list.head->data;
}
int Dequeue :: get_back() {
    if (is_empty()) return -1;
    else return list.tail->data;
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