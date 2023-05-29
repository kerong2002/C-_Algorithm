//2023/05/22 kerong
/*
   Algorithm : Max Heap
    Time complexity¡GO(log N)
   Space complexity¡GO(log N)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class MaxHeap {
private:
    vector<int> heap = {0};
    void heapifyUP(int index) {
        int parent = index / 2;
        while (index > 1 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = index / 2;
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if(largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:

    void insert(int value) {
        heap.push_back(value);
        heapifyUP(heap.size() - 1);
    }

    int removeMax() {
        if (heap.size() <= 1) {
           cerr << "Heap is empty!\n";
           return -1;
        }

        int maxNum = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
        return maxNum;
    }

    void printHeap() {
        for (int x = 0; x< heap.size(); ++x) {
            cout << setw(4) << heap[x];
        }
        cout << endl;
    }

};
int main() {
    MaxHeap maxHeap;
    maxHeap.insert(1);
    maxHeap.insert(5);
    maxHeap.insert(2);
    maxHeap.insert(4);
    maxHeap.insert(7);
    maxHeap.insert(9);
    maxHeap.insert(20);
    maxHeap.insert(11);
    maxHeap.insert(18);

    cout << "MaxHeap: ";
    maxHeap.printHeap();

    int maxElement = maxHeap.removeMax();
    cout << "Removed Max Element: " << maxElement << endl;

    cout << "Max Heap after removal: ";
    maxHeap.printHeap();

    for (int x= 0; x< 10; x++) {
        cout << "Removed Max Element: " << maxHeap.removeMax() << endl;
    }

    return 0;
}
