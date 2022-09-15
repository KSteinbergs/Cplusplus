#include<iostream>
using namespace std;
class Persona{
    long long PersKods;
public:
    Persona(long long nr){
        PersKods=nr;
    }
    ~Persona(){}
    void print() {
        cout<<"Personas Kods: "<<PersKods<<endl;
    }
};
class Students: public Persona {
    int AugSk; ///Augstskolas burtu sk
    char* Augstskola;
public:
    Students(long long nr, int sk, char* Augst):Persona(nr) {
        AugSk = sk;
        Augstskola = new char[AugSk+1];
        Augstskola = Augst;
    }
    ~Students() {
        cout << "Freeing Memory" << endl;
        delete []Augstskola;
    }
    void print() {
        Persona::print();
        cout << "Augstskola:"<<Augstskola;
        cout << endl;
    }

};
int main() {
    char skola[21]= "University of Latvia";
    Persona pers1(29040034395);
    pers1.print();
    cout<<endl;
    Students pers2(10059921229, 22, skola);
    pers2.print();
}
