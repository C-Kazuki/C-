//pure virtual function
//sampleprogram(1)
//make a order
//error messages
/*
	estfile.cpp:63:20: warning: conversion from string literal to 'char *' is
      deprecated [-Wc++11-compat-deprecated-writable-strings]
    DrinkBox cofee("コーヒー", 200, 3);
                   ^
testfile.cpp:64:24: warning: conversion from string literal to 'char *' is
      deprecated [-Wc++11-compat-deprecated-writable-strings]
    DrinkBox oolongtea("ウーロン茶", 150, 2);
                       ^
testfile.cpp:65:20: warning: conversion from string literal to 'char *' is
      deprecated [-Wc++11-compat-deprecated-writable-strings]
    AlcholBox wine("ワイン", 300, 2, 15.0);
                   ^
3 warnings generated.
*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class DrinkBox{
public:
    //contructor
    DrinkBox(){}
    DrinkBox(char *str, int n1, int n2){
        name = new char[strlen(str) + 1];
        strcpy(name, str);
        price = n1;
        count = n2;
    }
    //destructor
    ~DrinkBox(){
        delete [] name;
    }

    int GetTotalPrice(){
        return count * price;
    }

    void PrintTitle(){
        cout << "商品名\t\t単価\t数量\t金額" << endl;
    }
    void PrintData(){
        cout << name << "\t" << price  << "\t"
             << count << "\t" << GetTotalPrice() << endl;
    }

    char *name;
    int price;
    int count;
};

//派生クラす
class AlcholBox : public DrinkBox{
public:
    AlcholBox(char *str, int n1, int n2, float f){
        name = new char[strlen(str) + 1];
        strcpy(name, str);
        price = n1;
        count = n2;
        alcper = f;
    }
    void PrintTitle(){
        cout << "商品名　（度数[%]） \t単価\t数量\t金額" << endl;
    }
    void PrintData(){
        cout << name << "(" << alcper << ") \t" << price << "\t"
             << count << "\t" << GetTotalPrice() << endl;
    }
private:
    float alcper;
};

int main(){
    DrinkBox cofee("コーヒー", 200, 3);
    DrinkBox oolongtea("ウーロン茶", 150, 2);
    AlcholBox wine("ワイン", 300, 2, 15.0);

    cofee.PrintTitle();
    cofee.PrintData();
    oolongtea.PrintData();
    wine.PrintTitle();
    cofee.PrintData();

    int sum = cofee.GetTotalPrice() + oolongtea.GetTotalPrice()
                + wine.GetTotalPrice();
    cout << "\n***　合計金額" << sum << "円***" << endl;
    return 0;
}

