#include <iostream>
using namespace std;
#define max_size 1000

int parent(int i) {
    return i/2;
}
int leftchild(int i) {
    return 2*i;
}
int rightchild(int i) {
    return 2*i+1;
}
class BinaryHeap {
    public:int H[max_size], size;
    public:
        BinaryHeap() {
            size = -1;
            for (int i=0;i <max_size; i++) H[i] = 0;
        }
        void siftUp(int i) {
            while (i > 0 && H[parent(i)] < H[i])
            {
                swap(H[parent(i)] , H[i]);
                i = parent(i);
            }
        }
        void siftDown(int i) {
            int maxIndex = i;
            int l = leftchild(i), r = rightchild(i);

            if (l <= size && H[l]>H[maxIndex]) maxIndex = l;
            if (r <= size && H[r]>H[maxIndex]) maxIndex = r;
            if (i != maxIndex) {
                swap(H[maxIndex], H[i]);
                siftDown(maxIndex);
            }
        }
        void insert(int i) {
            if (size == max_size) return;
            size++;
            H[size] = i;
            siftUp(size);
        }
        int ExtractMax() {
            if (size == -1) return INT32_MIN;
            int maximum = H[0];
            H[0] = H[size];
            size--;
            siftDown(0);
            return maximum;
        }
        void remove (int i) {
            if (i > size) return;
            H[i] = INT32_MAX;
            siftUp(i);
            ExtractMax();
        }
        void changePriority(int i,int p) {
            int oldp;
            if (i >= 0 && i <= size) oldp = H[i];
            else return;
            H[i] = p;
            if (H[i] > H[parent(i)]) siftUp(i);
            else siftDown(i);
        }
        int getSize() {
            return size + 1;
        }
};

int main() {
    BinaryHeap h = BinaryHeap();
    h.insert(5);
    h.insert(4);
    h.insert(89);
    h.changePriority(1,39);
    cout << h.ExtractMax()<<endl;
    cout << h.ExtractMax() << endl;
}