#include<iostream> 
using namespace std;
string operator+(string a,int b)
{
string c=to_string(b); return a+c;
}
int main()
{
string a; int b; a="Hello"; b=123;
string s=a+b;
cout<<"Final string:"<<s<<endl;
}

