#include<iostream>
using namespace std;

class Super
{
    public:
        virtual void add(int a, int b) = 0;
        void add(int a, float b)
        {
            printf("%f\n", a+b);
        }
        
};

class Child:public Super
{
    public:
        void add(int a, float b)
        {
            printf("%f\n", a+b+5);
        }
        void add(int a, int b)
        {
            printf("%d\n", a+b+5);
        }
};


int main()
{
    Super *s=new Child();
    int a = 1;
    float b = 1.5;

    s->add(a, a);
    return 0; 
}
