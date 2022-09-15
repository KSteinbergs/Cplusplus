#include <iostream>
#include <fstream>
#include "GG_dds.cpp"
using namespace std;
/*******************************************

Kārlis Šteinbergs, ks19105

G7. Uzrakstīt funkciju, kas  izmet no saraksta tos elementus,
kuri lielāki par iepriekšējo (iepriekšējais elements ir tas, kurš norāda uz nākošo PIRMS izmešanas).

a) izmantojot dinamiskas datu struktūras (saistīto sarakstu vtml.),

** tas pats uzdevums, kas G, bet tā risinājums (a) jāpapildina ar divām lietām:
  1) vismaz viena no datu pārbaudēm jārealizē, izmantojot izņēmumsituāciju apstrādes (exception handling) mehānismu,
  2) vismaz viena funkcija (vēlams, galvenā) ir jānotestē, izmantojot vienībtestēšanu, kur attiecīgā funkcija būtu jāpārbauda uz vismaz
  trīs dažādiem nosacījumiem;
     šim nolūkam, kā minimums, ir nepieciešams:
     (1) šo funkciju iznest ārā citā failā (nekā funkcija main),
     (2) izveidot otru projektu speciāli šīs funkcijās testēšanai (tātad, kopā būs divi projekti, parastais, kas izmantos funkciju,
                                                                         otrais, kas testēs).

Programma izveidota: 2020/05/11

*******************************************/


int main ()
{
    /*elem *first=NULL, *last=NULL, *p;
    int i;
    cout<<"Ievadiet saraksta elementus ar 0 ka beigu simbolu:";
    do{
        try {
            i=input();
        }
        catch(const char *err) {
            cout<<err<<endl;
            i=1;
            cin.clear(); ///ja ievade ir bijusi neveiksmīga iztīra cin un to ignorē
            cin.ignore();
            continue;
        }
        if(!cin.fail()&&i!=0){ ///pārbauda vai ievade ir bijusi veiksmīga (int)
            add_element (first, last, i);
        }
    }while (i != 0);
    if(first!=NULL){
    //print_list (first);
    check(first);
    print_list (first);
    delete_list (first);
    }
    ///cikliskuma iespējas nosacījums
      cout<<"Vai turpinaat (1) vai beigt (jebkursh cits simbols)?"<<'\n';
      int atb;
      cin>>atb;
      if(atb==1){
        main();
      }*/
    ifstream test1("TestCases/Case1.txt");
    ifstream test2("TestCases/Case2.txt");
    ifstream test3("TestCases/Case3.txt");
    ifstream test4("TestCases/Case4.txt");
    ifstream test5("TestCases/Case5.txt");
    ifstream test6("TestCases/Case6.txt");
    tester(test1,1); ///Test of empty list
    tester(test2,2); ///Test of list with one item
    tester(test3,3); ///Test of list that does not need changes
    tester(test4,4); ///Test of list that needs to have a value removed from the middle and end
    tester(test5,5); ///Test of list where all values except first need to be removed (first value cant be less than its previous)
    tester(test6,6); ///Test of absolute worst case scenario
    return 0;
}
