#include<iostream> 
using namespace std; 
class test
{
private:
int a; int b; public:
static int count; test()
{
count++;
}
test(int a,int b)
{
this->a=a; this->b=b; count++;
}
};
int test::count=0; int main()
{
test obj[7];
test obj1(6,9),obj2(2,5);
cout<<"Total object created is "<<test::count<<endl;
}

