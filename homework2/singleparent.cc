// Jt Hepke
// Homeowork 2 assignment
// Code of recursive and iterative for binary trees single parent

#include <iostream>
#include <iomanip>
#include <stack> // iterative control
using namespace std;

//recursive function for single parent not linked to binary tree class
template <class Type>
void singleParentRecursive(nodeType<Type>* root, int& x) {
    //base checking
    if (root == nullptr){
        return;
    }

    // checking for single parent
    if ((root -> lLink == nullptr && root -> rLink != nullptr) || (root -> lLink != nullptr && root -> rLink == nullptr)){
        x++;
    }

    //left substree
    singleParentRecursive(root -> lLink, x);
    //right subtree
    singleParentRecursive(root -> rLink, x);
}

//iterative version using stack
template <class Type>
int singleParentIterative(nodeType<Type>* root){
    if(root == nullptr){
        return 0;
    }

    stack<nodeType<Type>*> s;
    nodeType<Type>* current;

    int x = 0; // the count

    s.push(root);

    while (!s.empty()) {
        current = s.top();
        s.pop();
        //check for single parent
        if ((current -> lLink == nullptr && current -> rLink != nullptr) || (current -> lLink != nullptr && current -> rLink == nullptr)){
            x++;
        }

        //push children to stack
        if (current -> rLink != nullptr) {
            s.push(current -> rLink);
        }
        if (current -> lLink != nullptr) {
            s.push(current -> lLink);
        }
    }
    
    return x;
}