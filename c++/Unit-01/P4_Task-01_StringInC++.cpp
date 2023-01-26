#include<iostream>
#include<string>
using namespace std;

void basicFunctions()
{
    string abc = "Hello World";
    
    //concatication
    string firstName = "Jon ";
    string lastName = "Doe";
    string fullName = firstName + lastName;
    string fullName2 = firstName.append(lastName); //append function
    cout << fullName <<endl;
    cout << fullName2 <<endl;
    
    //string length
    cout << abc.length() << endl;
    cout << abc.size() << endl;

    //access string
    for(int i=0;i<abc.length();i++)
    {
        cout << abc[i];
    }
    cout <<endl;
    
    //user input
    string s1, s2;
    cout <<"Enter string :";
    cin >> s1;
    cout <<s1<<endl;
    cout <<"Enter string 2:";
    getline(cin, s2);
    cout << s2 <<endl;
}

void printASCIIValue()
{
    string s1 = "Siddharth";
    for(int i=0;i<s1.length();i++)
    {
        cout << s1[i] <<" : "<<int(s1[i]) << endl;
    }
}

void replaceCharacter()
{
    string s1 = "Siddharth";
    for(int i=0;i<s1.length();i++)
    {
        if(int(s1[i])==97)
            s1[i] = 'b';
        if(int(s1[i])==65)
            s1[i] = 'B';
    }
    cout << s1 << endl;
}

void replaceCharacter2()
{
    string s1 = "Zakshitz asd qwer";
    cout << s1<< endl;
    for(int i=0;i<s1.length();i++)
    {
        if(( int(s1[i]) >=65 && (int(s1[i]) <=90)) || (int(s1[i]) >=97 && (int(s1[i]) <=122)) )
        {
            if(int(s1[i])==90)
                s1[i] = 65;
            else if(int(s1[i])==122)
                s1[i] = 97;
            else
                s1[i] = int(s1[i]+1); 
        }
    }
    cout << s1 << endl;
}


void invalidConcatination()
{
    //invalid concatination -->  mismatched types ‘const _CharT*’ and ‘int’ | no match for ‘operator+’
    string str = "ABC";
    int a = 10;
    //string z = str+a;
    //cout << z << endl;
}


void palindrome()
{
    string s;
    cin >> s;
    int i=0,j=s.length()-1;
    while(true)
    {
        if(s[i]!=s[j] || i>=j)
        {
            break;
        }
        i++;
        j--;
    }
    if(i>=j)
        cout << "palindrome" << endl;
    else   
        cout << "not palindrome" << endl;

}

void stringCompare()
{
    string s1 = "hello";
    string s2 = "Helloo";
    cout << (s1==s2) << endl;
    if(s1==s2)
        cout << "string are equal" << endl;
    else
        cout << "string are not equal" << endl;

    int i = s1.compare(s2);
    cout  << i << endl;

    if(i==0)
        cout << "string are equal" << endl;
    else    
        cout << "string are equal" << endl;

    if(i>0)    
        cout << "s1 > s2" << endl;
    if(i<0)
        cout << "s2 > s1" << endl;


}


void stringMutableOrNot()
{
    string s = "Hello";
    cout << &s[0]<<endl;
    s[0] = 'J';
    cout << &s[0]<<endl;
}

int main()
{
    basicFunctions();
    printASCIIValue();
    cout << endl;
    replaceCharacter();
    cout << endl;
    replaceCharacter2();
    palindrome();
    stringCompare();
    stringMutableOrNot();
}
