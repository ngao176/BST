#include "BST.h"
#include <vector>

BST::BST() { 
    /* YOUR CODE HERE */
    
    root = nullptr;
    numElements = 0;
}

BST::~BST() {
    /* YOUR CODE HERE */
    clear();
}

unsigned int BST::size() const {
    /* YOUR CODE HERE */
    return numElements;
}

void BST::clear() {
    /* YOUR CODE HERE */

    if (root == nullptr) {
        return;
    }
 
    vector<Node*> v;
    v.push_back(root);
 
    Node* x = nullptr;
 
    while (!v.empty()){
      
        x = v.back();
        v.pop_back();
 
        if (x->leftChild) {
            v.push_back(x->leftChild);
        }
 
        if (x->rightChild) {
            v.push_back(x->rightChild);
        }
     
        delete x;
    }
    numElements=0;
    root = nullptr;
}
    



bool BST::insert(int element) {
    /* YOUR CODE HERE */
    Node* x = new Node(element);

    if(root == nullptr){
        root = x;
        numElements++;
        return 1;
    }

    Node* par = nullptr;
    Node* y = root;

    while(y != nullptr) {
        if(y->data == element){
            delete x;
            return 0;
        }
        if (y->data > element) {
            par = y;
            y = y->leftChild;
        }
        else if (y->data < element) {
            par = y;
            y = y->rightChild;
        }
    }

    if(par->data >  element){
        par->leftChild = x;
    }else{
        par->rightChild = x;
    }
    
    y= x;
    x->parent = par;


    numElements++;
    return 1;
}

bool BST::find(const int & query) const {
    /* YOUR CODE HERE */
    Node* x = root;

    while(x != nullptr) {
  
        if(x->data == query){
            return 1;
        }else if(x->data > query){
            x = x->leftChild;
        }else{
            x = x->rightChild;
        }
    }
    return 0;
}

BST::Node* BST::getLeftMostNode() {
    /* YOUR CODE HERE */
    Node* x = root;
    if(x == nullptr){
        return nullptr;
    }

    while(x->leftChild != nullptr){
        x = x->leftChild;
    }
    return x;

}

BST::Node* BST::Node::successor() {
    /* YOUR CODE HERE */
    if (this->rightChild != nullptr){
        Node* y = this->rightChild;
        
        while (y->leftChild != nullptr) {
            y = y->leftChild;
        }
        return y;
    }

    Node* x = this->parent;
    Node* z = this;
    while (x != nullptr && z == x->rightChild) {
        z = x;
        x = x->parent;
    }
    return x;

}
