#include<iostream>
using namespace std;

class SuperClass1
{
    public:
        void display()
        {
            cout << "display() of superclass1" << endl;
        }
};

class SuperClass2
{
    public:
        void display()
        {
            cout << "display() of superclass2" << endl;
        }
};


class c:public SuperClass1, SuperClass2
{
    public:
        c()
        {
            SuperClass1::display();
            SuperClass2::display();
        }
};

int main()
{
    c ob;
}
