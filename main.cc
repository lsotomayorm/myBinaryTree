#include <iostream>
#include "binaryTree.hpp"

int main(){
  BinaryTree<int> r;
  r.printTree();
  r.insert( 5 );
  r.insert( 3 );
  r.insert( 7 );
  r.printTree();
  std::cout << r.size() << std::endl;
  std::cout << r.maxDepth() << std::endl;
  return 0;
}