#include<iostream>
using namespace std;


void ternaryOperators()
{
    int a = 5, b=2;
    cout << a++ <<endl;
    cout << a <<endl;
    cout << ++a <<endl;
    cout << a-- <<endl;
    cout << a <<endl;
    cout << --a <<endl;


    if(a>1 && b<3)
    {
        cout <<  "logical operator"<< endl;
    }
    if(a>1 & b<3)
    {
        cout <<  "bitwise operator"<< endl;
    }

    //ternary
    int n1=10, n2=12, n3=13;
    int max, max3;
    max = (n1>n2)? n1: n2;
    max3 = (n1>n2)? (n1>n3)? n1 : n3 :(n2>n3)? n2 : n3;
    cout << "Ternary : " << max << endl;
    cout << "Ternary 3  : " << max3 << endl;
}

int main()
{
    int a = 10;
    int b = 12;

    //Arthmetic  Operator [+,-,*,/]
    cout << a+b << endl; //22
    cout << a-b << endl; //2
    cout << a*b << endl; //120
    cout << a/b << endl; //

    //Remainder Operator [%]
    cout << a%b << endl; //10
    
    //Arthmetic Assingment Opertor
    int c=10;
    c += a; // c = c + a;
    cout << a << endl;

}

