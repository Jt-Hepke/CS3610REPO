// using a min heap it would take O (n log n) time
// no min heap would be lineaer search for smallest making it O (n ^ 2)



#include <iostream>
#include "huffman_tree.h"
using namespace std;

int main(int argc, char** argv) {

  HuffmanTree tree;

  int T;
  cin >> T;
  cin.ignore();
  for (int t = 1; t <= T; ++t) {
    cout << "Test Case: " << t << endl;

    string message;
    getline(cin, message);

    // Create a HuffmanTree object and read the input messages into the
    // HuffmanTree construct function. Next, print the encoded message.
    // Finally, destruct the huffman tree and move on to the next test case.
				     
    tree.construct(message);
    tree.print();
    tree.destruct();
  }

}
