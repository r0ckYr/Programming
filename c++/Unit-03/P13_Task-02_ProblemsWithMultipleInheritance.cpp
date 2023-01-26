#include<iostream>
using namespace std;

class A
{
    public:
        void displayA()
        {
            cout << "display of A" << endl;
        }
};

class B:virtual public A
{
    public:
        void displayB()
        {
            cout << "display of B" << endl;
        }
};
class C:virtual public A
{
    public:
        void displayC()
        {
            cout << "display of C" << endl;
        }
};
class D:public B, public C
{
    public:
        void displayD()
        {
            cout << "display of D" << endl;
        }
};


int main()
{
    D ob;
    ob.displayD();
    ob.displayC();
    ob.displayB();
    //cannot be called without virtual
    ob.displayA();
}
