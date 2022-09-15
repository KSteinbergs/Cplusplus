#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*******************************************

Karlis Šteinbergs, ks19105

F16. Dots teksta fails, kurā atrodas sintaktiski pareizs C++ programmas teksts. Saskaitīt, cik salīdzināšanas operatoru (==, !=, <=, >=)
satur dotā programma. Drīkst uzskatīt, ka programmas tekstā nav komentāru un ka attiecīgie simboli neparādīsies teksta literāļos.

Programma izveidota: 2020/02/20

*******************************************/


int main()
{
    ifstream file("myfile.txt");
    string temp;
    int nr=0; ///skaita salīdzināšanas
    while(getline(file, temp)){
            //cout<<temp<<endl;
            for(int i=0; i<((int)temp.length()-1);i++){
                ///Atrod salīdzināšanas
                if(temp.substr(i,2)=="=="||temp.substr(i,2)=="!="||temp.substr(i,2)=="<="||temp.substr(i,2)==">="){
                    //cout<<temp.substr(i,2);
                    i++;
                    nr++;
                }
            }
    }
    cout<<endl<<"atrastas "<<nr<<" salidzinasanas"<<endl;
    return 0;
}
