#include <iostream>
using namespace std;

class darray {
    int *arr, capacity;
    public:
        int size;
        darray () {
            arr = new int[2];
            size = 0;
            capacity = 2;
        }
        int get(int index) {
            if (index < 0 || index >= size) return INT8_MIN;
            return *(arr + index);
        }
        void set(int index, int val) {
            if (index < 0 || index >= size) return;
            *(arr + index) = val;
        }
        void pushBack(int val) {
            if (size == capacity) {
                int *temp = new int[capacity*2];
                capacity *= 2;
                for (int var = 0; var < size; var++) {
                    *(temp + var) = *(arr + var);
                }
                delete arr;
                arr = temp;
            }
            *(arr + size) = val;
            size++;
        }
        void remove(int index) {
            // Does not decrease the capacity of the dynamic array
            if (index < 0 || index >= size) return;
            for (int var = index; var < size - 1; var++) {
                *(arr + var) = *(arr + var + 1);
            }
            size--;
        }
};


int main() {
    darray arr;
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    cout << arr.get(2)<< endl;
}