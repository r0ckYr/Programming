#include<iostream>
using namespace std;

class Super
{
    public:
        virtual void add(int a, int b)
        {
            printf("%d\n", a+b);
        }
        void add(int a, float b)
        {
            printf("%f\n", a+b);
        }
};

class Child:public Super
{
    public:
        void add(int a, int b)
        {
            printf("%d\n", a+b+5);
        }
        
        void add(int a, float b)
        {
            printf("%f\n", a+b+5);
        }
};


int main()
{
    Super *s=new Super();
    Super *c=new Child();
    int a = 1;
    float b = 1.5;

    s->add(a, b);
    c->add(a, b);
    //using virtual function
    s->add(a,a);
    c->add(a,a);
    return 0; 
}
