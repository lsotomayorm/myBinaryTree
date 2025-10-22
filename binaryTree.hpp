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
    std::cout << node->value << ", ";
    printTreeRecu( node->right );
  }

  int sizeRecu( const Node<T>* node ){
    if( !node ) return 0;
    return 1 + sizeRecu( node->left ) + sizeRecu( node->right );
  }

  int maxDepthRecu(const Node<T>* node){
    if( !node ) return 0;

    int depthLeft = 1 + maxDepthRecu( node->left );
    int depthRight = 1 + maxDepthRecu( node->right );
    
    return depthLeft > depthRight ? depthLeft : depthRight;
  }

  bool isBSTRec1(const Node<T>* node){
    if( !node ) return true; //Baso base: 1. arbol nulo es BST. 2. hijos de hojas termina el nivel de recursion
    if( node->left && node->value < node->left->value )
      return false;
    if( node->right && node->value >= node->right->value )
      return false;
    //Si algun subarbol retorna false entonces no es BST
    if( !isBSTRec1( node->left ) ) return false;
    if( !isBSTRec1( node->right ) ) return false;
    //Si se llega a este punto entonces es BST
    return true;
  }

  public:
  BinaryTree() : root( nullptr ){}

  void insert( const T& value ){
    root = insertRecu( root, value );
  }

  void printTree(){
    printTreeRecu( root );
    std::cout << std::endl;
  }

  int size(){
    return sizeRecu( root );
  }

  int maxDepth(){
    return maxDepthRecu( root );
  }

  bool isBST( root ){

  }
};