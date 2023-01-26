#include<iostream>
#include<cmath>
using namespace std;

void forAllNPrimeOrNot(int n)
{
    int i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            cout << "Not Prime" << endl;
            return;
        }
    }
    cout << "Prime" <<endl;
}

void forHalfNPrimeOrNot(int n)
{
    int i;
    for(i=2;i<n/2;i++)
    {
        if(n%i==0)
        {
            cout << "Not Prime" << endl;
            return;
        }
    }
    cout << "Prime" <<endl;
}


void forSqrtNPrimeOrNot(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            cout << "Not Prime" << endl;
            return;
        }
    }
    cout << "Prime" <<endl;
}


int sqrt1(int n)
{
    for(int i=1;i<n/2;i++)
    {
        if(i*i==n)
            return i;
    }
    return n-1;
}


void forSqrt1NPrimeOrNot(int n)
{
    int i;
    for(i=2;i<=sqrt1(n);i++)
    {
        if(n%i==0)
        {
            cout << "Not Prime" << endl;
            return;
        }
    }
    cout << "Prime" <<endl;
}


int main()
{
    int n;
    cin >> n;
    
    forAllNPrimeOrNot(n); 
    forHalfNPrimeOrNot(n);
    forSqrtNPrimeOrNot(n);
    forSqrt1NPrimeOrNot(n);

    return 0;
}
