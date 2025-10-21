#include <iostream>

template <typename T>
struct Node{
  T value;
  Node* left;
  Node* right;

  Node( const T& data ) : value( data ), left( nullptr ), right( nullptr ){}
};

template <typename T>
class BinaryTree{
  private:
  Node<T>* root;

  Node<T>* createNode(const T& value){
    //Node<T>* newNode = new Node<T>( value );
    //return newNode;
    return new Node<T>( value );
  }

  Node<T>* insertRecu( Node<T>* node, const T& value ){
    if( !node ) return createNode( value );
    if( value <= node->value )
      node->left = insertRecu( node->left, value );
    else
      node->right = insertRecu( node->right, value );
    return node;
  }
  //inorder
  void printTreeRecu( const Node<T>* node){
    if( !node ) return;
    printTreeRecu( node->left );
    std::cout << node->value << ", " << "\n";
    printTreeRecu( node->right );
  }

  public:
  BinaryTree() : root( nullptr ){}

  void insert( const T& value ){
    root = insertRecu( root, value );
  }

  void printTree(){
    printTreeRecu( root );
  }
};