/**********************************************************
Jared Falcon
cs211
5/9/21

This program is the binary search tree class. Recursion will 
be used in order to traverse the tree. 
 *********************************************************/
#include <iostream>
#include <cstdlib> //for rand()
#include <fstream>
//#include "LL.h"
using namespace std;

typedef int el_t;

class Node
{
  friend class BST;
private:
  el_t elem;
  Node* right;
  Node* left;
public:
  Node(el_t e){elem = e, right = NULL, left = NULL;} //implement the constructor inside the class definition
};

class BST
{
private:
  Node* root;
  void insertNode(Node*& p, el_t e);
  void destroy(Node* p);
  void inOrderPrint(Node* p);
  void preOrderPrint(Node* p);
  void postOrderPrint(Node* p);
  int getNumNodes(Node* p);
  int getMaxLength(Node* p);
  bool searchRec(Node* p, el_t e);
  void printNodesBetween(Node* p, int min, int max);
  int getNumNodesBetween(Node* p, int min, int max);
public:
  BST();
  ~BST();
  void insertNode(el_t e);
  bool search(el_t e);
  void inOrderPrint();
  void preOrderPrint();
  void postOrderPrint();
  int getNumNodes();
  int getMaxLength();
  bool searchRec(el_t e);
  void printNodesBetween(int min, int max);
  int getNumNodesBetween(int min, int max);
};
//constructor 
BST::BST()
{
  root = NULL;
}
//destructor 
BST::~BST()
{
  destroy(root);
}
/*******************************************
p will be the root
This function will delete the nodes in the tree.
 ******************************************/
void BST::destroy(Node* p)
{
  if(p == NULL)
    return;
  destroy(p->left);
  destroy(p->right);
  //  cout << p->elem << "-->";
  delete p;
}
/*************************************************
min is the minimum 
max is the maximum 

This is the public function that calls our private 
function.
 ************************************************/
int BST::getNumNodesBetween(int min, int max)
{
  return getNumNodesBetween(root, min, max);
}
/************************************************
min is the minimum
max is the maximum
p is the root

This function will return the number of nodes within
a range. 
 ***********************************************/
int BST::getNumNodesBetween(Node* p, int min, int max)
{

  if(p == NULL)//base case
    return 0;
  if(p->elem == max && p->elem == min)//if our min and max are the same and theres a number equal to them it will return 1
    return 1;
  if(p->elem <= max && p->elem >= min)//if the number is in the range, add the numbers from the right and left tree as well as adding one for the root
    return 1 + getNumNodesBetween(p->left, min, max) + getNumNodesBetween(p->right, min, max);
  if(p->elem < min)//if our minimum is lower move right
    return getNumNodesBetween(p->right, min, max);
  if(p->elem > max)//if our element is bigger than max move left
    return getNumNodesBetween(p->left, min, max);
 
}
/***************************************************
min is the minimum
max is the maximum

This fucntion will call the private print function. 
 **************************************************/
void BST::printNodesBetween(int min, int max)
{
  return printNodesBetween(root, min, max);
}
/******************************************************
min is the minimum
max is the maximum
p is the root

This function will check if the node's value is withing 
a certain range and print them out in ascending order.
 *****************************************************/
void BST::printNodesBetween(Node* p, int min, int max)
{
  if(p == NULL)//base case
    return;

  if(min < p->elem)//smaller than our range
    printNodesBetween(p->left, min, max);
  if(min <= p->elem && max >= p->elem)//if number is in range print it
    cout << p->elem << " ";
  if(max > p->elem)//number is outside our range , bigger than max
    printNodesBetween(p->right, min, max);

}
//public funtion will call private
int BST::getMaxLength()
{
  return getMaxLength(root);
}
/*****************************************************
P is the root

This function will return the max length of the tree.
 ***************************************************/
int BST::getMaxLength(Node* p)
{
  int left;//stores the left sided nodes
  int right;//stores right nodes
  
  if(p == NULL)//if p is null return 0
    return 0;
  left = getMaxLength(p->left) + 1;//count the nodes on the left and add 1 for the root
  right = getMaxLength(p->right) + 1; //count the nodes on the right and add 1 for the root
  if(left >= right)//compare the left and right side, return whatever is bigger
    return left;
  else
    return right;
}
/*****************************************************
public function that calls our private function
 ****************************************************/
int BST::getNumNodes()//public function
{
  return getNumNodes(root);
}
/**************************************************
p is the root

THis function will return the number of nodes in the
tree.
 **************************************************/
int BST::getNumNodes(Node* p)//private function
{
  if(p == NULL) //no more nodes below
    return 0;
  else//count all the nodes in the tree and count the root
    return getNumNodes(p->left) + getNumNodes(p->right) + 1; 
}
/*****************************************************
public function that calls our private function
****************************************************/
void BST::postOrderPrint()
{
  postOrderPrint(root);
}
/****************************************************
p is the root

THis fucntion will print the nodes in post order form
the parent at the end 
 **************************************************/
void BST::postOrderPrint(Node* p)
{
  if(p == NULL)//return if theres nothing
    return;
  postOrderPrint(p->left);//look in the left
  postOrderPrint(p->right);//look right
  cout << p->elem << "-->";//parent at the end
}
/*****************************************************
public function that calls our private function
****************************************************/
void BST::preOrderPrint()
{
  preOrderPrint(root);
}
/****************************************************
p is the root

This function will print the tree in pre order form
The parent will be first.
 ***************************************************/
void BST::preOrderPrint(Node* p)
{
  if(p == NULL)
    return;
  cout << p->elem << "-->";//parent first 
  preOrderPrint(p->left);//go left
  preOrderPrint(p->right);//go right

}
/*****************************************************
public function that calls our private function
****************************************************/
void BST::inOrderPrint()
{
  inOrderPrint(root);
}
/***************************************************
THis fucntion will print the tree in order form
The parent in the middle
 *************************************************/
void BST::inOrderPrint(Node* p)
{
  if(p == NULL)
    return;
  inOrderPrint(p->left);//check left
  cout << p->elem << "-->";//parent in the middle
  inOrderPrint(p->right);//check right

}
/***************************************************
public function that calls our private function
 *************************************************/
void BST::insertNode(el_t e)//public
{
  insertNode(root, e);
}
/*************************************************
p is the root
e is the element to insert

This fucntion will allow us to enter a new node in the
tree.
 *************************************************/
void BST::insertNode(Node*& p, el_t e)//private
{
  if(p == NULL)
    p = new Node(e);//make new node
  else if(e < p->elem)//check if its smaller, insert 
    insertNode(p->left, e);
  else//check if its smaller, insert
    insertNode(p->right, e);
}
/***************************************************
public function that calls our private function
*************************************************/
bool BST::searchRec(el_t e)
{
  return searchRec(root, e);
}
/****************************************************
p is the root
e is the element to insert

This fucntion will search for a node in the tree.
 ***************************************************/
bool BST::searchRec(Node* p, el_t e)
{
  if(p == NULL)
    return false;
  else if(p->elem == e)//the elemenst match
    return true;
  else if(p->elem > e)//search left side
    return searchRec(p->left, e);
  else//search right side
    return searchRec(p->right, e);
      
}
/******************************************************
e is the element to be inserted 

This fucntion is a non-recursive function that will search 
the tree and see if its in there.
 *****************************************************/
bool BST::search(el_t e)
{
  //Don't use recursion. Use a loop.
  Node* p = root;
  int counter = 0;
  while(p)//while p is pointing to a node
    {
      if(p->elem == e)//if the elements is found, return true  
	{
	  cout << counter << " nodes checked" << endl;
	  return true;
	}
      else if(e < p->elem)//if the e is less than p->elem, search left 
	{
	  p = p->left;
	}
      else
	{
	  p = p->right;//if the e is greater than p->elem, search right
	}
      counter++;
    }
  cout << counter << " nodes checked" << endl;
  return false;
}

int main()
{
  srand(time(0)); //you need to include cstdlib
  
  BST Tree;//our tree
  // LL List;
  int num;//used to read the file numbers
  int s;//used for min
  int l;//used for max
  // int SIZE = 10000;//
  ifstream fin;
  fin.open("bst.dat");
  if(!fin)
    {
      cout << "File broke" << endl;
    }
  else
    {
      fin >> num;
      while(fin)
	{
	  Tree.insertNode(num);
	  fin >> num;
	}
      fin.close();
    }
  //  Tree.inOrderPrint();
  // cout << Tree.getNumNodes() << endl;
  cout << endl;
  cout << "Enter the min: ";
  cin >> s;
  cout << "Enter the max: ";
  cin >> l;

 
  cout << "The number of nodes between " << s << " and " << l << " is " << Tree.getNumNodesBetween(s, l) << endl;
  cout << "---------- The number between " << s << " and " << l << " found in the tree are ------------" << endl;
  Tree.printNodesBetween(s, l);
  cout << endl;
  /*
  BST b;
  
  b.insertNode(5);
  b.insertNode(8);
  b.insertNode(3);
  b.insertNode(9);
  b.insertNode(4);
  b.insertNode(1);
  // b.insertNode(2);
  b.insertNode(6);
  b.insertNode(7);
  b.insertNode(0);
  //b.insertNode(10);
  b.insertNode(20);
  
  cout << "max length" << endl;
  cout << b.getMaxLength() << endl;

  cout << "number of nodes" << endl;
  cout << b.getNumNodes() << endl;

  cout << "Find a node" << endl;
  int key;
  cout << "Enter key: ";
  cin >> key;
  if(b.searchRec(key))
    {
      cout << key << " was found" << endl;
    }
  else
    cout << key << " was NOT found" << endl;
  cout << endl;
  cout << "----Print all elements using the in-order traversal -----" << endl;
  b.inOrderPrint();
  cout << endl;
  //  cout<< "\n---destructor gets called ---" << endl;
  cout << endl;
  

  cout << "----Print all elements using the pre-order traversal -----" << endl;
  b.preOrderPrint();
  cout << endl;
  cout << endl;

  cout << "----Print all elements using the post-order traversal -----" << endl;
  b.postOrderPrint();
  cout << endl;
  
  cout<< "\n---destructor gets called ---" << endl;
  cout << endl;
  */
  //cout << "max length" << endl;
  //cout << b.getMaxLength() << endl;
  //random = rand() % 10000 + 1;
  /*
    for(int i = 0; i < SIZE; i++)
    {
      
    random = rand() % 10000 + 1;
    //      cout << random << endl;
    Tree.insertNode(random);
    List.addFront(random);
    }
    
    
  int key;
  cout << "What number do you want to search for? ";
  cin >> key;


  cout << "BST *************************" << endl;

  
  if(Tree.search(key)== true)
    {
      cout << key << " found! " << endl;
    }
  else
    {
      cout << key << " was NOT found!" << endl;
    }
  


  cout << "LL************************" << endl;

  if(List.search(key)== true)
    {
      cout << key << " found! " << endl;
    }
  else
    {
      cout << key << " was NOT found!" << endl;
    }
  */
 
    

  return 0;
}
