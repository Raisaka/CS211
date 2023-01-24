//Test client to test DLL class
//5-7-2016
//CS211  Kazumi Slott
//Jared Falcon
#include <iostream>
using namespace std;
#include "DLL.h"

int main()
{
  DLL l;
  
  cout << "TEST addRead, delteFront, displayAll, printAllReverseDLL **********************************************" << endl;


  cout << "------------ A -------------" << endl;

  if(l.isEmpty())
    cout << "The list is empty" << endl;  // "The list is empty"

  l.displayAll(); // [empty]
  cout << endl;

   
  l.printAllReverseDLL(); // [empty]
  cout << endl;

   


  cout << "------------ B -------------" << endl;

  l.addRear(1);

  l.displayAll(); // 1
  cout << endl;

   
  l.printAllReverseDLL(); // 1
  cout << endl;

   


  cout << "------------ C -------------" << endl;
  
  l.addRear(2);
  l.addRear(3);
  l.addRear(4);

  l.displayAll(); // [1] -> [2] -> [3] -> [4]
  cout << endl;

   
  l.printAllReverseDLL(); // [4] -> [3] -> [2] -> [1]
  cout << endl;

   


  cout << "------------ D -------------" << endl;
  
  cout << l.deleteFront() << " has been removed" << endl;  //1 has been removed
  cout << l.deleteFront() << " has been removed" << endl;  //2 has been removed
  cout << l.deleteFront() << " has been removed" << endl;  //3 has been removed

  l.displayAll(); // [4]
  cout << endl;

   
  l.printAllReverseDLL(); // [4] 
  cout << endl;

   


  cout << "------------ E -------------" << endl;
  

  if(!l.isEmpty())
    cout << "The list is NOT empty" << endl;  // "The list is NOT empty"


  cout << l.deleteFront() << " has been removed" << endl;  //4 has been removed


  if(l.isEmpty())
    cout << "The list is empty" << endl;  // "The list is empty"


  l.displayAll(); // [empty]
  cout << endl;

   
  l.printAllReverseDLL(); // [empty] 
  cout << endl;

   



  cout << "TEST addFront, deleteRear **************************************************************" << endl;

  cout << "------------ A -------------" << endl;

  l.addFront(1); 
  l.addFront(2);
    
  l.addFront(3);
    
  l.addFront(4);
    
  l.addFront(5);
    

  l.displayAll();  // 5 4 3 2 1
  
  cout << endl;

   
  l.printAllReverseDLL(); // 1 2 3 4 5
  cout << endl;

   

  cout << "------------ B -------------" << endl;

  cout << l.deleteRear() << " has been removed" << endl; //1 has been removed 
  cout << l.deleteRear() << " has been removed" << endl; //2 has been removed

  l.displayAll(); //5 4 3
  cout << endl;

   
  l.printAllReverseDLL(); // 3 4 5
  cout << endl;

   

  cout << "------------ C -------------" << endl;

  cout << endl << endl;

    
  cout << l.deleteRear() << " has been removed" << endl; //3 has been removed
  cout << l.deleteRear() << " has been removed" << endl; //4 has been removed 
  l.displayAll(); //5
  cout << endl;

   
  l.printAllReverseDLL(); // 5
  cout << endl;

   

  cout << "------------ D -------------" << endl;

  cout << l.deleteRear() << " has been removed" << endl; // 5 has been removed
  l.displayAll(); //[empty]
  cout << endl;

   
  l.printAllReverseDLL(); // [empty]
  cout << endl;

   


  cout << "TEST Search **************************************************************" << endl;

  DLL l2;
  l2.addRear(3);
  l2.addRear(9);
  l2.addRear(2);
  l2.addRear(1);
  l2.addRear(9);
  l2.addRear(11);

  cout << l2.search(3) << endl;  //1
  cout << l2.search(11) << endl; //1
  cout << l2.search(2) << endl;  //1
  cout << l2.search(9) << endl;  //1
  cout << l2.search(100) << endl; //0
 
  
  cout << "TEST deleteNode **************************************************************" << endl;

  cout << "------------ A -------------" << endl;

  l.addRear(3);
  l.addRear(9);
  l.addRear(2);
  l.addRear(1);
  l.addRear(9);
  l.addRear(11);
  l.displayAll();  //[3] -> [9] -> [2] -> [1] -> [9] -> [11]
  cout << endl;
  l.printAllReverseDLL(); // 11  9  1  2  9  3
  cout << endl;

  cout << "------------ B -------------" << endl;

  l.deleteNode(9);
  l.displayAll();  //[3] -> [2] -> [1] -> [9] -> [11]
  cout << endl;
  l.printAllReverseDLL();  // 11 9 1 2 3
  cout << endl;

  cout << "------------ C -------------" << endl;

  l.deleteNode(9);
  l.displayAll(); //[3] -> [2] -> [1] -> [11]
  cout << endl;
  l.printAllReverseDLL();  // 11 1 2 3
  cout << endl;

  cout << "------------ D -------------" << endl;

  l.deleteNode(5); 
  l.displayAll(); //[3] -> [2] -> [1] -> [11]
  cout << endl;
  l.printAllReverseDLL();  // 11 1 2 3
  cout << endl;

  cout << "------------ E -------------" << endl;

  l.deleteNode(3); 
  l.displayAll(); //[2] -> [1] -> [11]
  cout << endl;
  l.printAllReverseDLL();  // 11 1 2
  cout << endl;

  cout << "------------ F -------------" << endl;

  l.deleteNode(11); 
  l.displayAll(); //[2] -> [1]
  cout << endl;
  l.printAllReverseDLL(); // 1 2
  cout << endl;

  cout << "------------ G -------------" << endl;

  l.deleteNode(1); 
  l.displayAll(); //[2]
  cout << endl;
  l.printAllReverseDLL(); // 2
  cout << endl;

  cout << "------------ H -------------" << endl;

  l.deleteNode(2); 
  l.displayAll(); //[empty]
  cout << endl;
  l.printAllReverseDLL(); //[empty]
  cout << endl;

  l.deleteNode(5); // Nothing happens
  

  cout << "addInOrder**************************************************************" << endl;

  cout << "------------ A -------------" << endl;

  l.addInOrderAscend(5);
  l.displayAll(); //[5]
  cout << endl;
  l.printAllReverseDLL(); //5
  cout << endl;

  cout << "------------ B -------------" << endl;

  l.addInOrderAscend(1);
  l.displayAll(); //[1] -> [5]
  cout << endl;
  l.printAllReverseDLL(); // 5 1
  cout << endl;

  cout << "------------ C -------------" << endl;

  l.addInOrderAscend(3);
  l.displayAll(); //[1] -> [3] -> [5]
  cout << endl;
  l.printAllReverseDLL(); // 5 3 1
  cout << endl;

  cout << "------------ D -------------" << endl;

  l.addInOrderAscend(0);
  l.displayAll(); //[0]->[1]->[3]->[5]
  cout << endl;
  l.printAllReverseDLL(); // 5 3 1 0
  cout << endl;

  cout << "------------ E -------------" << endl;

  l.addInOrderAscend(7);
  l.displayAll(); //[0]->[1]->[3]->[5]->[7]
  cout << endl;
  l.printAllReverseDLL();  // 7 5 3 1 0
  cout << endl;

  cout << "------------ F -------------" << endl;

  l.addInOrderAscend(7);
  l.displayAll(); //[0]->[1]->[3]->[5]->[7]->[7]
  cout << endl;
  l.printAllReverseDLL();  // 7 7 5 3 1 0
  cout << endl;

  cout << "------------ G -------------" << endl;

  l.addInOrderAscend(5);
  l.displayAll(); //[0]->[1]->[3]->[5]->[5]->[7]->[7]
  cout << endl;
  l.printAllReverseDLL(); // 7 7 5 5 3 1 0
  cout << endl;

  cout << "------------ H -------------" << endl;

  l.addInOrderAscend(0);
  l.displayAll(); //[0]->[0]->[1]->[3]->[5]->[5]->[7]->[7]
  cout << endl;
  l.printAllReverseDLL(); // 7 7 5 5 3 1 0 0
  cout << endl;


  
    cout << "##### EXTRA CREDIT -  TEST deleteNodes (all occurences) **************************************************************" << endl;

    cout << "------------ A -------------" << endl;
    
  l2.displayAll(); //[3] -> [9] -> [2] -> [1] -> [9] -> [11]
  cout << endl;

  l2.deleteNodes(9);
  l2.displayAll(); //[3] -> [2] -> [1] -> [11]
  cout << endl; 
  l2.printAllReverseDLL();  //11 1 2 3
  cout << endl;

  cout << "------------ B -------------" << endl;

  l2.addRear(3);
  l2.displayAll(); //[3] -> [2] -> [1] -> [11] -> [3]
  cout << endl;

  l2.deleteNodes(3);
  l2.displayAll(); //[2] -> [1] -> [11]
  cout << endl; 
  l2.printAllReverseDLL();  //11 1 2
  cout << endl;

  cout << "------------ C -------------" << endl;

  l2.addRear(5);
  l2.displayAll(); //[2] -> [1] -> [11] -> [5]
  cout << endl;

  cout << "------------ D -------------" << endl;

  l2.deleteNodes(2); 
  l2.displayAll(); //[1] -> [11] -> [5]
  cout << endl; 
  l2.printAllReverseDLL(); // 5  11  1
  cout << endl;

  cout << "------------ E -------------" << endl;

  l2.deleteNodes(11); 
  l2.displayAll(); //[1] -> [5]
  cout << endl; 
  l2.printAllReverseDLL();  //5 1
  cout << endl;

  cout << "------------ F -------------" << endl;

  l2.deleteNodes(5); 
  l2.displayAll(); //[1]
  cout << endl; 
  l2.printAllReverseDLL(); //1
  cout << endl;

  cout << "------------ G -------------" << endl;

  l2.deleteNodes(1); 
  l2.displayAll(); //[empty]
  cout << endl; 
  l2.printAllReverseDLL();  //[empty]
  cout << endl;

  l2.deleteNodes(100); //nothing happens


  cout << "##### EXTRA CREDIT - TEST addInOrderDescend **************************************************************" << endl;

  cout << "------------ A -------------" << endl;

  l2.addInOrderDescend(5);
  l2.displayAll(); //[5]
  cout << endl;  
  l2.printAllReverseDLL(); //5
  cout << endl;

  cout << "------------ B -------------" << endl;

  l2.addInOrderDescend(1);
  l2.displayAll(); //[5] -> [1]
  cout << endl; 
  l2.printAllReverseDLL(); // 1 5
  cout << endl;

  cout << "------------ C -------------" << endl;

  l2.addInOrderDescend(3);
  l2.displayAll(); //[5] -> [3] -> [1] 
  cout << endl; 
  l2.printAllReverseDLL();  // 1 3 5 
  cout << endl;

  cout << "------------ D -------------" << endl;

  l2.addInOrderDescend(0);
  l2.displayAll(); //[5] -> [3] -> [1] -> [0]
  cout << endl; 
  l2.printAllReverseDLL(); // 0 1 3 5
  cout << endl;

  cout << "------------ E -------------" << endl;

  l2.addInOrderDescend(7);
  l2.displayAll(); //[7] -> [5] -> [3] -> [1] -> [0]
  cout << endl; 
  l2.printAllReverseDLL(); // 0 1 3 5 7 
  cout << endl;

  cout << "------------ F -------------" << endl;

  l2.addInOrderDescend(7);
  l2.displayAll(); //[7] -> [7] -> [5] -> [3] -> [1] -> [0]
  cout << endl; 
  l2.printAllReverseDLL(); // 0 1 3 5 7 7
  cout << endl;

  cout << "------------ G -------------" << endl;

  l2.addInOrderDescend(5);
  l2.displayAll(); //[7] -> [7] -> [5] -> [5] -> [3] -> [1] -> [0]
  cout << endl; 
  l2.printAllReverseDLL(); // 0 1 3 5 5 7 7
  cout << endl;

  cout << "------------ H -------------" << endl;

  l2.addInOrderDescend(0);
  l2.displayAll(); //[7] -> [7] -> [5] -> [5] -> [3] -> [1] -> [0] -> [0] 
  cout << endl; 
  l2.printAllReverseDLL(); // 0 0 1 3 5 5 7 7
  cout << endl;
  

  return 0;
}

