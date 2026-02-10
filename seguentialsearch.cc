#include <iostream>
using namespace std;

template <class T>
class arrayListType {
    private:
        T *list;
        int length;
        int maxSize;

        int seqSearchRecursive(const T& item, int loc) const;
    
    public:
        arrayListType(int size) {
            maxSize = size;
            length = 0;
            list = new T[maxSize];
        }
        
        void insert(const T& item) {
            if (length < maxSize) {
                list[length] = item;
                length++;
            }
        }
        
        int seqSearch(const T& item) const;
        
        ~arrayListType() {
            delete[] list;
        }
};

template <class T>
int arrayListType<T>::seqSearch(const T& item) const {
    return seqSearchRecursive(item, 0);
}

template <class T>
int arrayListType<T>::seqSearchRecursive(const T& item, int loc) const {
    if (loc >= length) {
        return -1;
    }
    if (list[loc] == item) {
        return loc;
    }
    return seqSearchRecursive(item, loc + 1);
}

int main() {
    arrayListType<int> myList(10);
    myList.insert(35);
    myList.insert(12);
    myList.insert(27);
    myList.insert(18);
    myList.insert(45);
    
    cout << "Searching for 27: " << myList.seqSearch(27) << endl;
    cout << "Searching for 10: " << myList.seqSearch(10) << endl;
    
    return 0;
}