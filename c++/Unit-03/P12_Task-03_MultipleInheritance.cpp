#include<iostream>
using namespace std;

class Mammal
{
    public:
        void display1()
        {
            cout << "I am Mammal" << endl;
        }

};


class MarineAnimal
{
    public:
        void display2()
        {
            cout << "I am a Marine Animal" << endl;
        }
};


class BlueWhale:public Mammal,public MarineAnimal
{
    public:
        void display3()
        {
            cout << "I belong to both the categories: Mammals as well as Marine Animals" << endl; 
        }
};


int main()
{
    Mammal mammal;
    MarineAnimal marineAnimal;
    BlueWhale blueWhale;

    mammal.display1();
    marineAnimal.display2();
    blueWhale.display3();
    blueWhale.display1();
    blueWhale.display2();
}
