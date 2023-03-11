#include <iostream>
using namespace std;
#include "linkedlist.h"

int main(){
  LinkedList < int > A;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #1  * " << endl;
  cout << " ***************** " << endl;


  cout << "Is the list empty? " << boolalpha << A.isEmpty() <<endl; 
  cout << A << endl;
  cout << "Size of A = " << A.size() << endl;

  //TEST : Inserting 10 numbers to a
  cout << endl << "TEST : Inserting 10 numbers to A. back" << endl;
  for (int k=0; k<10; k++){
    A.insert_back(k*2+1);
  } 
  cout << A << endl;
  cout << "Size of a = " << A.size() << endl;
  /*
  //TEST : Inserting 10 numbers to a
  cout << endl << "TEST : Inserting 10 numbers to A, front" << endl;
  for (int k=0; k<10; k++){
    A.insert_front(k*2);
  } 
  cout << A << endl;
  cout << "Size of a = " << A.size() << endl;

  cout << endl << "Test 01 - Done!" << endl;
  
  //TEST : Destroying A  
  */

}