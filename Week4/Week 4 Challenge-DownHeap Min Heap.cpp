/*
Implement downHeap(Node *n) for a min heap implemented as an ordinary binary tree with an integer member variable "value" and left and right child pointers. Unlike the video lesson which implemented downHeap on an array implementation of a complete binary tree, the binary tree in this challenge problem is not stored as an array and is not necessarily complete; any node might have only a left child, only a right child, both, or neither.

The starter code below defines a class called "Node" that has two child pointers ("left" , "right") and an integer "value" member variable. There is also a constructor Node(int val) that initializes the children to nullptr and the node's value to val.

Your job is to implement the procedure "downHeap(Node *n)" . The procedure should assume that n->left is the root of a min heap subtree (or nullptr) and the same for n->right. The value at Node *n (specifically n->value) might not be less than the values in its left subtree and in its right subtree, and so the tree with Node *n as its root might not be a min heap (even though its left subtree and right subtree are both min heaps). Your code should modify the tree rooted at Node *n so it is a min heap. You do not need to balance the tree or turn it into a complete tree. You only need to ensure that the tree satisfies the min heap property:

For a min heap, it is okay for a node's value to be equal to one or both of its children, but the node's value must not be greater than either of its children.
*/

/*

Implement below the downHeap procedure for a min heap.

Unlike the video lessons which demonstrated downHeap
implemented with an array implementation, this assignment
uses an ordinary binary tree with left and right child
pointers. This ordinary binary tree might not be complete
or balanced: any node might have only one child or the other,
or both, or neither.

Suppose you are given a tree where the left and right
subtrees are min heaps, but the root node does not
maintain the min heap property. Your code should
modify the tree rooted at Node* n so it is a min heap.
(This means you need to satisfy the min heap property:
it is okay for a node's value to be equal to one or both
of its children, but the node's value must not be greater
than either of its children. You do not have to try to
balance the tree or make it a complete tree.)

Tips:
If the root node exists, and if it has a left or right
child, and if one of the children has a smaller value
than the root node, then you should swap the root node
with the smaller child to move the large value down
into the tree. (This may need to be done recursively.)
Be careful to check whether pointers are null before
dereferencing them, as always; that includes using "->"
to access a class member through a pointer. In addition,
you must be careful not to accidentally compare "left"
and "right" pointers directly if you really intend to
compare the stored values "left->value" and "right->value".

Assume that these headers have already been included
for you:

#include <iostream>
#include <string>

You have the following class Node already defined.
You cannot change this class definition, so it is
shown here in a comment for your reference only:

class Node {
public:
  int value;
  Node *left, *right;
  Node(int val = 0) { value = val; left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

This function has also previously been defined for you:

void printTreeVertical(const Node* n);

You can use it to print a verbose, vertical diagram of
a tree rooted at n. In this vertical format, a left child
is shown above a right child in the same column. If no
child exists, [null] is displayed.

*/

void downHeap(Node *n) {
  // Implement downHeap() here.
  
  // BL: Check node vs children and swap if either child is smaller
  if(n->left) { 
    std::cout << "Checking parent " << n->value << " vs left child " << n->left->value << std::endl;
    if(n->value > n->left->value) {
      // BL: child is larger so swap values
      std::cout << "** Swapping " << n->value << " with left child " << n->left->value << std::endl;
      int temp = n->left->value;
      n->left->value = n->value;
      n->value = temp;
      
    } 
    
    // BL: now run recursively down all nodes on left branch
    std::cout << "Moving down left to " << n->left->value << std::endl;
    downHeap(n->left);
  }
  
  if(n->right) { 
    std::cout << "Checking parent " << n->value << " vs right child " << n->right->value << std::endl;
    if(n->value > n->right->value) {
      // BL: child is larger so swap values
      std::cout << "** Swapping " << n->value << " with right child " << n->right->value << std::endl;
      int temp = n->right->value;
      n->right->value = n->value;
      n->value = temp;
    } 
    
    // BL: now run recursively down all nodes on right branch
    std::cout << "Moving down right to " << n->right->value << std::endl;
    downHeap(n->right);  
  }
}

// You can also use this compact printing function for debugging.
void printTree(Node *n) {
  if (!n) return;
  std::cout << n->value << "(";
  printTree(n->left);
  std::cout << ")(";
  printTree(n->right);
  std::cout << ")";
}

int main() {
  Node *n = new Node(100);
  n->left = new Node(1);
  n->right = new Node(2);
  n->right->left = new Node(3);
  n->right->right = new Node(4);
  n->right->right->right = new Node(5);

  downHeap(n);

  std::cout << "Compact printout:" << std::endl;
  printTree(n);
  std::cout << std::endl << "Vertical printout:" << std::endl;
  printTreeVertical(n);

  delete n;
  n = nullptr;

  return 0;
}
