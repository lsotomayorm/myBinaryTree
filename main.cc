#include "binaryTree.hpp"

int main(){
  BinaryTree<int> r;
  r.printTree();
  r.insert( 5 );
  r.insert( 3 );
  r.insert( 7 );
  r.printTree();
  return 0;
}