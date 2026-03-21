#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
struct HeapNode {
  HeapNode(const T data, const int key) : data(data), key(key) {}
  bool operator<(const HeapNode<T>& rhs) {return this->key < rhs.key;}
  bool operator<=(const HeapNode<T>& rhs) {return this->key <= rhs.key;}

  T data;
  int key;
};

template <typename T>
class MinHeap {
public:
  MinHeap() {}
  ~MinHeap() {}

  void insert(const T data, const int key);
  T extract_min();
  T peek() const {
    return heap[0].data;
  } // need to implement this function

  int size() const {
    return heap.size();   
  }         // need to implement this function

private:
  vector<HeapNode<T> > heap;
};


template <typename T>
void MinHeap<T>::insert(const T data, const int key) {  // need to implement this function
  HeapNode<T> node(data, key); // new heap with all data
  heap.push_back(node); // push it to the end

  int i = heap.size() - 1; // start index i at the last index

  //bubble up moving the heap 
  while (i > 0) {
    int parent = (i - 1) / 2;

    if (heap[i].key >= heap[parent].key){ // if in the right spot -> stop
      break;
    }

    swap(heap[i], heap[parent]); // if not in the right spot swap
    i = parent; // move it up
  }
}

template <typename T>
T MinHeap<T>::extract_min() {                          // need to implement this function

  T data = heap[0].data; // save root

  heap[0] = heap.back(); // move the last element up to the root
  heap.pop_back(); // then remove that last element

  int i = 0;

  while(true) { // fix heap by moving node down
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    // checking the left child
    if (left < heap.size() && heap[left].key < heap[smallest].key){
      smallest = left;
    }
    // checking the right child
    if (right < heap.size() && heap[right].key < heap[smallest].key){
      smallest = right;
    }

    //equal children
    if (right < heap.size() && heap[left].key == heap[right].key && heap[left].key < heap[i].key){
      smallest = left;
    }

    if(smallest == i){ // when correct stop
      break;
    }
    swap(heap[i], heap[smallest]); // to swap the smaller children
    i = smallest;
  }
  
  return data;
}
