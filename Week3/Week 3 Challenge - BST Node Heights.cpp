/* Week 3 Challenge - Calculate Binary Tree Node Heights

Implement a function that computes the height of each node in a binary tree and stores it in each node of the tree. Recall that the height of a node is the number of edges in its longest chain of descendants.

Consider a tree with root node A that has two child nodes B1 and B2. Let node B1 have no children. Let node B2 have one child C. Then the height of A would be two, because its longest chain of descendants (A -> B2 -> C) has two edges (A -> B2 and B2 -> C).

The starter code below defines a class called "Node" that has two child pointers ("left" , "right") and an integer "height" member variable. There is also a constructor Node() that initializes the children to nullptr and the height to -1.

Your job is to implement the procedure "computeHeight(Node *n)" that computes the height of the node n as well as the height of its children (if any).

There is also a helper function "printTree(const Node *n)" that prints the current heights showing the tree as embedded parentheses. If a child is nullptr, then it will appear as an empty pair of parentheses: "()". The constructor initializes the height to -1 even though a node with no children should have a height of zero. If you see any -1 entries after you've run your computeHeight() procedure, you may have missed one or more nodes.

The helper function printTreeVertical(const Node *n) is also available to you (although its complex definition is not shown). It displays a verbose, vertical printout of your tree, where the root is shown at the top, and left children are shown on higher rows than right children.
*/


/*
The height of a node is the number of edges in
its longest chain of descendants.

Implement computeHeight to compute the height
of the subtree rooted at the node n. Note that
this function does not return a value. You should
store the calculated height in that node's own
height member variable. Your function should also
do the same for EVERY node in the subtree rooted
at the current node. (This naturally lends itself
to a recursive solution!)

Assume that the following includes have already been
provided. You should not need any other includes
than these.

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

You have also the following class Node already defined.
You cannot change this class definition, so it is
shown here in a comment for your reference only:

class Node {
public:
  int height; // to be set by computeHeight()
  Node *left, *right;
  Node() { height = -1; left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};
*/

// BL: Create a recursive function to count children 
int countChildren(Node *n) {
  int h = 0, hLeft = 0, hRight = 0;
  
  // calculate # of children in each leg
  if (n->left) { 
    hLeft++;
    // std::cout << "Found a child on left" << std::endl;
    hLeft += countChildren(n->left); 
  }
  if (n->right) { 
    hRight++;
    // std::cout << "Found a child on right" << std::endl;
    hRight += countChildren(n->right); 
  }
  // set height h equal to the longest leg
  // std::cout << "* Left leg: " << hLeft << " vs Right leg: " << hRight << std::endl;
  hLeft >= hRight ? h = h + hLeft : h = h + hRight;
  std::cout << "** Setting height to: " << h << std::endl; 
  n->height = h;
  return h;
}

void computeHeight(Node *n) {
  // Implement computeHeight() here.
  
  Node *curr, *pre;
  curr = n;
  
  // BL: Calculate height of root
  curr->height = countChildren(n);

  // BL: Check a few to see if it worked
  // std::cout << "Height of n: " << n->height << std::endl;
  // std::cout << "Height of n left: " << n->left->height << std::endl;
  // std::cout << "Height of n right: " << n->right->height << std:: endl;
  // std::cout << "Height of n right left: " << n->right->left->height << std:: endl;
  // std::cout << std::endl;

}

// This function prints the tree in a nested linear format.
void printTree(const Node *n) {
  if (!n) return;
  std::cout << n->height << "(";
  printTree(n->left);
  std::cout << ")(";
  printTree(n->right);
  std::cout << ")";
  if(!n->left && !n->right) { std::cout << "*"; } // BL: print a * at bottom of each leg
}

// The printTreeVertical function gives you a verbose,
// vertical printout of the tree, where the leftmost nodes
// are displayed highest. This function has already been
// defined in some hidden code.
// It has this function prototype: void printTreeVertical(const Node* n);

// This main() function is for your personal testing with
// the Run button. When you're ready, click Submit to have
// your work tested and graded.
int main() {
  Node *n = new Node();
  n->left = new Node();
  n->right = new Node();
  n->right->left = new Node();
  n->right->right = new Node();
  n->right->right->right = new Node();

  computeHeight(n);

  printTree(n);
  std::cout << std::endl << std::endl;
  printTreeVertical(n);
  
  // The Node destructor will recursively
  // delete its children nodes.
  delete n;
  n = nullptr;

  return 0;
}
