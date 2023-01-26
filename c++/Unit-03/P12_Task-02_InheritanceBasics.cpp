#include<iostream>
using namespace std;

class SuperClass
{
    public:
        SuperClass()
        {
            cout << "Super Class Constructor" << endl;
        }

        void display()
        {
            cout << "Super class display() method" << endl;
        }
};


class BaseClass:public SuperClass
{
    public:
        int a;
        BaseClass()
        {
            cout << "Base Class Constructor" << endl;
            display();
        }
};


int main()
{
    BaseClass b;
    b.display();
}
