#include <iostream>
using namespace std;
#include "linkedlist.h"

int main(){
  LinkedList <int> A;
  LinkedList <int> B;
  LinkedList <int> C;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #4  * " << endl;
  cout << " ***************** " << endl;

  //TEST : Inserting 10 elements to a
  cout << endl << "TEST : Inserting 10 elements into A" << endl;
  for (int k=0; k<10; k++){
    A.insert_front(k*10);
  } 
  cout << A << endl;
  cout << "Size of A = " << A.size() << endl;
  
  //TEST : Inserting 10 elements into b
  cout << endl << "TEST : Inserting 10 elements into B" << endl;
  for (int k=0; k<10; k++){
    B.insert_front(20+k*5);
  } 
  cout << B << endl;
  cout << "Size of B = " << B.size() << endl;
  
  // TEST : Comparison Operator==;
  cout << endl << "TEST : Comparison" << endl;
  cout << "Is A == B ? " << boolalpha << (A == B) << endl;
  /*
  // TEST : Operator=
  cout << endl << "TEST : Operator=" << endl;
  C = A;
  cout << "A = " << A << " " << A.size() << endl;
  cout << "C = " << C << " " << C.size() << endl;
  cout << "Is A == C ? " << boolalpha << (A == C) << endl;
  
  cout << endl << "Making sure is a deep copy" << endl;
  C.insert_front(42);
  C.insert_back(43);
  cout << "A = " << A << " " << A.size() << endl;
  cout << "C = " << C << " " << C.size() << endl;
  
  
  // TEST : Copy Constructor
  cout << endl << "TEST : Copy Constructor" << endl;
  LinkedList<int> D ( A );
  cout << "A = " << A << " " << A.size() << endl;
  cout << "D = " << D << " " << D.size() << endl;
  cout << "Is A == D ? " << boolalpha << (A == D) << endl;
  
  cout << endl << "Making sure is a deep copy" << endl;
  D.insert_front(111);
  D.insert_back(222);
  cout << "A = " << A << " " << A.size() << endl;
  cout << "D = " << D << " " << D.size() << endl;
	
  cout << endl << "Test 04 - Done!" << endl;
  */

}