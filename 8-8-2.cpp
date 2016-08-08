//call a static member function
#include<iostream>
using namespace std;

/*
Undefined symbols for architecture x86_64:
  "Food::tax", referenced from:
      Food::SetTax(double) in testfile-6a1326.o
      Food::GetTax() in testfile-6a1326.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
*/


class Food{
public:
    static void SetTax(double n){
        tax = n;
    }
    static void GetTax(){
        cout << tax << endl;
    }
protected:
    static double tax;
};

int main(){
    Food myFood;
    myFood.SetTax(1.03);
    myFood.GetTax();
    return 0;
}




