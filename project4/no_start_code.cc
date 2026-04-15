// Jt Hepke
// Project 4
// Heap version



#include <iostream>

using namespace std;

//Heap node
struct HeapNode {
    int dist; // shortest distance
    int cityIndex; // what index is what city
};

// Minheap class
// city with the smallest distance away is always on top
class MinHeap {
    public:
        HeapNode heap[100];
        int lookupTable[100];
        int size;

        // sets up heap
        void build(int dist[], int n) {
            size = n;
            for (int i = 0; i < n; i++){
                heap[i].dist = dist[i];
                heap[i].cityIndex = i;
                lookupTable[i] = i;
            }

            for (int i = (size / 2) -1; i >= 0; i--){
                bubbleDown(i);
            }
        }

        // true if no cities in heap
        bool isEmpty() {
            return size == 0;
        }
        // true if city is still in the heap or not used yet
        bool inHeap(int cityIndex) {
            return lookupTable[cityIndex] != -1;
        }

        // will remove and return the city with the smallest of distances
        HeapNode extractMin() {
            HeapNode minNode = heap[0];
            size--;
            heap[0] = heap[size];
            lookupTable[heap[0].cityIndex] = 0;
            lookupTable[minNode.cityIndex] = -1;
            bubbleDown(0);
            return minNode;
        }

        // called when have shorter path with a city already in the heap
        void decreaseKey(int cityIndex, int newDist) {
            int pos = lookupTable[cityIndex];
            heap[pos].dist = newDist;
            bubbleUp(pos);
        }

        // moves node up the heap
        void bubbleUp(int pos) {
            while (pos > 0) {
                int parent = (pos - 1) / 2;
                if (heap[pos].dist < heap[parent].dist){
                    swapNodes(pos, parent);
                    pos = parent;
                }
                else{
                    break;
                }
            }
        }

        // moves node down the heap
        void bubbleDown(int pos) {
            while (true) {
                int left = 2 * pos + 1;
                int right = 2 * pos + 2;
                int smallest = pos;

                if (left < size && heap[left].dist < heap[smallest].dist) {
                    smallest = left;
                }
                if (right < size && heap[right].dist < heap[smallest].dist){
                    smallest = right;
                }
                if (smallest != pos){
                    swapNodes(pos, smallest);
                    pos = smallest;
                }
                else {
                    break;
                }
            }
        }

        //swaps nodes in the heap array
        void swapNodes(int a, int b){
            lookupTable[heap[a].cityIndex] = b;
            lookupTable[heap[b].cityIndex] = a;
            HeapNode temp = heap[a];
            heap[a] = heap [b];
            heap[b] = temp;
        }
};


int main() {
    int inputNum;
    cin >> inputNum;

    for (int u = 0; u < inputNum; u++){
        //read input
        int cityNum;
        cin >> cityNum;

        string city[100];
        for (int j = 0; j < cityNum; j++){
            cin >> city[j];
        }

        int distance[100][100];
        for (int j = 0; j < cityNum; j++){
            for (int t = 0; t < cityNum; t++){
                cin >> distance[j][t];
            }
        }

        int d[100]; 
        int prev[100];

        for (int j = 0; j < cityNum; j++){
            //intatilize everything
            d[j] = 99999;
            prev[j] = -1;
        }
        d[0] = 0; // distance from itself is 0
        MinHeap h;
        h.build(d, cityNum);

        //goes untill all cites are used and isempty is true
        while (!h.isEmpty()) {
            HeapNode node = h.extractMin();   
            int u = node.cityIndex;

            if (node.dist == 99999) break;

            for (int i = 0; i < cityNum; i++){
                 if (distance[u][i] > 0 && h.inHeap(i)) {  
                    int newDistance = d[u] + distance[u][i];
                    if (newDistance < d[i]) {
                        d[i] = newDistance;
                        prev[i] = u;
                        h.decreaseKey(i, newDistance); 
                    }
                }
            }
        }

        int path[100];
        int pathLength = 0;
        int currentpath = cityNum - 1; 

        while (currentpath != -1){
            path[pathLength] = currentpath;
                pathLength++;
                currentpath = prev[currentpath];

        }

        // The pathway is stored backwards so printing is reversed
        for (int i = pathLength - 1; i >= 0; i--){
            cout << city[path[i]];
            if(i != 0){
                cout << " "; // space between cities
            }
        }
        cout << " " << d[cityNum - 1] << endl;
    }
}