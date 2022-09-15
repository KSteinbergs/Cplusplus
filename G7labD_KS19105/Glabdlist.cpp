#include <iostream>
#include <list>
#include <iterator>
using namespace std;

/*******************************************

Kārlis Šteinbergs, ks19105

G7. Uzrakstīt funkciju, kas  izmet no saraksta tos elementus,
kuri lielāki par iepriekšējo (iepriekšējais elements ir tas, kurš norāda uz nākošo PIRMS izmešanas).

Programma izveidota: 2020/03/17

*******************************************/

///lista printēšana
void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it) cout << '\t' << *it;
    cout << '\n';
}
///pārbauda vai nākošais elements ir liekāks par iepriekšējo
void check(list <int>& g){
    list <int> :: iterator it = g.begin();
    int previous = *it;
    ++it;
    for(; it != g.end(); ){
        //cout<<previous<<" "<<*it<<endl;
        if (previous<*it){
            previous=*it;
            it=g.erase(it);
        }else {
            previous=*it;
            ++it;
        }
    }
}

main(){
    int i;
    cout<<"Ievadiet saraksta elementus ar 0 ka beigu simbolu:";
    list <int> glist;
    do{
        cin>>i;
        if(!cin.fail()&&i!=0){ ///pārbauda vai ievade ir bijusi veiksmīga (int)
            glist.push_back(i);
        }else if (cin.fail()){
            i=1;
            cin.clear(); ///ja ievade ir bijusi neveiksmīga iztīra cin un to ignorē
            cin.ignore();
        }
    }while (i != 0);
    showlist(glist);
    check(glist);
    showlist(glist);
    glist.clear(); ///atbrīvo atmiņu
    ///cikliskuma iespējas nosacījums
      cout<<"Vai turpinaat (1) vai beigt (jebkursh cits simbols)?"<<'\n';
      int atb;
      cin>>atb;
      if(atb==1){
        main();
      }
}

