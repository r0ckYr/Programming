#include<iostream> 
#define rentalcharge 500 
using namespace std; 
class Telcall
{ private:
long long phno; string sname; int n;
float amt=0; public:
Telcall(long long a,string b,int c)
{
phno=a; sname=b; n=c;
}
void compute()
{ if(n<=100)
amt=rentalcharge; else if(n<=200)
amt=n*1.00+rentalcharge; else if(n<=300) amt=n*1.20+rentalcharge; else
amt=n*1.50+rentalcharge;
}
void display()
{cout<<"Name="<<sname<<endl; cout<<"Phone number="<<phno<<endl; cout<<"Billing amount="<<amt<<endl; }
};
int main()
{
Telcall obj(8979912700,"Siddharth Singh Rana",1000); obj.compute();
obj.display();
}
