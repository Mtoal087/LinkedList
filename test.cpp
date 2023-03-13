#include <iostream>
using namespace std;
#include "linkedlist.h"

int main(){
  LinkedList<int> A;
  LinkedList<int> B;
  LinkedList<int> C;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #5  * " << endl;
  cout << " ***************** " << endl;

  //TEST : Inserting 10 elements to a
  cout << endl << "TEST : Inserting 7 elements into A and B" << endl;
  for (int k=0; k<7; k++){
    A.insert_front(k*2+10);
    B.insert_front(3*k+10);
  } 
  cout << "A = " << A << " " << A.size() << endl;
  cout << "B = " << B << " " << B.size() << endl;

  // TEST : Append
  cout << endl << "TEST : Append B into A" << endl;
  A.append(B);
  cout << "Making sure it is a deep copy.." << endl;
  B.insert_back(77);
  cout << B << " " << B.size() << endl;
  cout << A << " " << A.size() << endl;  
    
  // TEST : Reverse;
  cout << endl << "TEST : Reversing A" << endl;
  A.reverse();
  cout << A << " " << A.size() << endl;
/*
  // TEST : Purge;
  cout << endl << "TEST : Purging A" << endl;
  A.purge();
  cout << A << " " << A.size() << endl;


  LLNode<int> *p;
  LLNode<int> *q;
  // TEST : Slice
  cout << endl << "TEST : Slicing B into C from '22' to '13' " << endl;
  p = B.find(22);
  q = B.find(13);
  C.slice(B, p, q); 
  cout << "C = " << C << " " << C.size() << endl;


  cout << endl << "Test 05 - Done!" << endl;
  
*/
}