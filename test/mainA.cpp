// string::at
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*******************************************

Kārlis Šteinbergs, ks19105

A9. Dots naturāls skaitlis n. Noskaidrot dotā skaitļa ciparu skaitu un ciparu summu. Skaitļa dalīšana ciparos jāveic skaitliski.

Programma izveidota: 2019/09/18

*******************************************/

int main (){
  ///definē vērtību "nr", kas būs lietotāja ievadītais skaitlis String formā
  cout<<"Ievadi naturalu skaitli"<<'\n';
  string nr;
  cin >>nr;
  int x=0, sum=0, y, z;
  ///Konvertē lietotāja ievadīto vērtību int formā
  stringstream geek(nr);
  geek>>z;
  //cout<<"Z="<<z<<'\n';
  ///ciparu skaita noskaidrošana un summas iegūšana skaitliski
  for (unsigned i=0; i<nr.length(); ++i){
    ///ievadītās vērtības pārbaude (vai tajā nav burti)
    y= nr.at(i);
    if (y>=48&&y<=57){
      sum+=z%10;
      //cout<<"Summa="<<sum<<'\n';
      z=z/10;
      x++;
    }else x=i=999; ///izejas kondīcija, ko varam izmantot veelāk
  }
  if (x==999){
    cout<<"nepareizs datu tips"<<'\n';
  }else cout << " ciparu skaits ir "<<  x << " ciparu summa ir " << sum<<'\n';
  ///programmas atkārtotas izmantošanas iespējas nodrošināšana
  cout<<"Vai turpinaat (1) vai beigt (jebkursh cits simbols)?"<<'\n';
  int atb;
  cin>>atb;
  if(atb==1){
    main();
  }
  return 0;
}
