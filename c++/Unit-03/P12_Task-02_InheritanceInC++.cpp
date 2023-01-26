#include<iostream>
using namespace std;

class SuperClass
{
    public:
        int a = 12;
        SuperClass()
        {
            cout << "Super Class Constructor" << endl;
            cout << a << endl;
        }
};

class BaseClass:public SuperClass
{
    public:
        int a = 10;
        BaseClass()
        {
            cout << "Base Class Constructor" << endl;
            cout << a << endl;
        }
};

int main()
{
    BaseClass b;
}

