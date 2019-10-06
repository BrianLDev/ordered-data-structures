// WEEK 2 CHALLENGE - BINARY SEARCH TREE COUNT 

/********************************************************
You may assume that the following Node class has already
been defined for you previously:

class Node {
public:
  Node *left, *right;
  Node() { left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

You may also assume that iostream has already been included.

Implement the function "int count(Node *n)" below to return
an integer representing the number of nodes in the subtree
of Node n (including Node n itself).

*********************************************************/
using namespace std;

int count(Node *n) {
  // Implement count() here.
  int cnt = 0;

  Node *curr, *pre;
  curr = n;
  
  while (curr != nullptr) {
  
    if (curr->left == nullptr) { 
      cnt++; 
      curr = curr->right; 
    } 
    else { 
      pre = curr->left; 
      while (pre->right != nullptr && pre->right != curr) 
          pre = pre->right; 

      if (pre->right == nullptr) { 
          pre->right = curr; 
          curr = curr->left; 
      } 
      else { 
          pre->right = nullptr; 
          cnt++; 
          curr = curr->right; 
      }
    }
  }

  return cnt;
}

int main() {
  Node *n = new Node();
  n->left = new Node();
  n->right = new Node();
  n->right->left = new Node();
  n->right->right = new Node();
  n->right->right->right = new Node();

  // This should print a count of six nodes
  std::cout << count(n) << std::endl;

  // Deleting n is sufficient to delete the entire tree
  // because this will trigger the recursively-defined
  // destructor of the Node class.
  delete n;
  n = nullptr;

  return 0;
}