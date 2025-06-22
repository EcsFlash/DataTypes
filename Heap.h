#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class MaxHeap {
private:
    vector<int> heap;
    void toUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }

    void toDown(int root_index) {
        while (true) {
            int leftSon_index = 2 * root_index + 1;
            int rightSon_index = 2 * root_index + 2;
            int toSwap_index = root_index;
            if (leftSon_index < heap.size() && heap[leftSon_index] > heap[toSwap_index]) {
                toSwap_index = leftSon_index;
            }
            if (rightSon_index < heap.size() && heap[rightSon_index] > heap[toSwap_index]) {
                toSwap_index = rightSon_index;
            }
            if (toSwap_index != root_index) {
                swap(heap[root_index], heap[toSwap_index]);
                root_index = toSwap_index;
            }
            else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        toUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            throw "no mama";
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        toDown(0);
        return minValue;
    }

    int peekMin() const {
        if (heap.empty()) {
            throw "no mama";
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void fromArray(vector<int> arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            toDown(i);
        }
    }
};
