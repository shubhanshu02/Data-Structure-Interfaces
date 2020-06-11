#include <iostream>
using namespace std;
#define size 50

class Dequeue {
    int arr[size] = {0};
    int front;
    int rear;
    public:
        Dequeue() {
            rear = front = -1;
        }
        bool is_full();
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
        cout << "\n1: is_full\n" << "2: is_empty\n" << "3: push_front\n" <<  "4: push_back\n" << "5: pop_front\n";
        cout << "6: pop_back\n" <<"7: get_front\n" << "8: get_back" << endl;
        cin >> temp;
        switch (temp)
        {
        case 1:
            cout << d.is_full() << endl;
            break;
        case 2:
            cout << d.is_empty() << endl;
            break;
        case 3:
            int x;cin >> x;
            d.push_front(x);
            break;
        case 4:
            int t;cin >> t;
            d.push_back(x);
            break;
        case 5:
            d.pop_front();
            break;
        case 6:
            d.pop_back();
            break;
        case 7:
            cout << d.get_front()<< endl;
            break;
        case 8:
            cout << d.get_back()<< endl;
            break;
        default:
            cout <<"INVALID INPUT" << endl;
            break;
        }
    }
    
    

}

void Dequeue :: push_front(int val) {
    if (is_full()) {
        cout << "Overflow" << endl;
    }
    else if (front == rear && rear == -1) {
        front = rear = 0;
        arr[front] = val;
    }
    else {
        if (front == 0) front = size - 1;
        else front--;
        arr[front] = val;
    }
}

void Dequeue :: push_back(int val) {
    if (is_full()) {
        cout << "Overflow" << endl;
    }
    else if (front == rear && rear == -1) {
        front = rear = 0;
        arr[rear] = val;
    }
    else {
        if (rear == size -1) rear = 0;
        else rear++;
        arr[rear] = val;
    }
}

bool Dequeue :: is_full() {
    if ((rear == front-1) || (front == -1 && rear == size-1)) return true;
    else return false;
}

bool Dequeue :: is_empty() {
    if (front == -1) return true;
    else return false;
}

void Dequeue :: pop_back() {
    if (is_empty()) {
        cout << "Underflow" << endl;
    }
    else {
        if (rear == front) rear = front = -1;
        else if (rear == 0) rear = size -1;
        else rear--;
    }
}

void Dequeue :: pop_front() {
    if (is_empty()) {
        cout << "Underflow" << endl;
    }
    else {
        if (rear == front) rear = front = -1;
        else if (front == size-1) front = 0;
        else front++;
    }
}

int Dequeue :: get_front() {
    if (is_empty()) {
        cout << "Underflow" << endl;
        return -1;
    }
    else return arr[front];
}

int Dequeue :: get_back() {
    if (is_empty()) {
        cout << "Underflow" << endl;
        return -1;
    }
    else return arr[rear];
}