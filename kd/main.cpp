#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it) cout << '\t' << *it;
    cout << '\n';
}
///pārbauda vai nākošais elements ir liekāks par iepriekšējo
void check(list <int>& g){
    list <int> :: iterator it = g.begin();
    list <int> :: iterator nx = it;
    ++nx;
    for(; nx != g.end(); ){
        //cout << '\t' << *it<<'\t'<<*nx<<'\t'<<*g.end()<<endl;
        if (*it%2==0&&*nx%2==1){
            g.erase(it);
            return;
        }else {++it;}
        nx = it;
        ++nx;
    }
}

main(){
    int i;
    cout<<"Ievadiet saraksta elementus ar 0 ka beigu simbolu:";
    cin >> i;
    list <int> glist;
    while (i != 0)
    {
        glist.push_back(i);
        cin >> i;
    }
    showlist(glist);
    check(glist);
    showlist(glist);
    glist.clear();
    ///cikliskuma iespējas nosacījums
      cout<<"Vai turpinaat (1) vai beigt (jebkursh cits simbols)?"<<'\n';
      int atb;
      cin>>atb;
      if(atb==1){
        main();
      }
}
