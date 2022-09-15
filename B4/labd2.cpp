#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*******************************************

Kārlis Šteinbergs, ks19105

B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi cipari. Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars ir sastopams. Skaitļa dalīšana ciparos jāveic skaitliski.

Programma izveidota: 2019/09/24

*******************************************/

int main (){
  ///definē vērtību "nr", kas būs lietotāja ievadītais skaitlis String formā
  cout<<"Ievadi naturalu skaitli"<<'\n';
  string nr;
  cin >>nr;
  int x=0, y, z, b, c=0;
  int m[10];
  ///masīva, kuru izmantošu biežuma vērtību saglabāšanai inicializācija
  for (unsigned a=0; a<10; ++a ){
    m[a]=0;
  }
  ///Konvertē lietotāja ievadīto vērtību int formā
  stringstream g(nr);
  g>>z;
  cout<<z;
  ///ciparu skaita noskaidrošana un summas iegūšana skaitliski
  for (unsigned i=0; i<nr.length(); ++i){
    ///ievadītās vērtības pārbaude (vai tajā nav burti)
    y= nr.at(i);
    if (y>=48&&y<=57){
  ///ciparu noteikšana skaitliski un to biežuma ievadīšana masīvā
      b=z%10;
      m[b]++;
      z=z/10;
      x++;
    }else x=i=999; ///izejas nosacījums, ko varam izmantot vēlāk
  }
  if (x==999){
    cout<<"nepareizs datu tips"<<'\n';
  }else{
      for (unsigned a=0; a<10; ++a){
        if(m[a]>=2){
            cout<<"Cipars "<<a<<" skaitlii "<<nr<<" atkaartojas "<<m[a]<<" reizes"<<'\n';
            c++;
        }
      }
      if(c==0){
        cout<<"Skaitlī "<<g<<" cipari neatkārtojas";
  }
  }
  ///cikliskuma iespējas nosacījums
  cout<<"Vai turpinaat (1) vai beigt (jebkursh cits simbols)?"<<'\n';
  int atb;
  cin>>atb;
  if(atb==1){
    main();
  }
}
