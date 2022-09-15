#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

/*******************************************

Kārlis Šteinbergs, ks19105

C6. Doti naturāls skaitlis n un veseli skaitļi a(1), a(2), ... a(n). Atrast skaitli, kurš dotajā virknē atkārtojas  visvairāk reižu pēc kārtas.
Cik reizes? Ja tādi skaitļi ir vairāki, tad izdrukāt lielāko.

Programma izveidota: 2019/10/07

*******************************************/

int inputcheck(string b){ ///funkcija pārbauda vai ievadītajos datos nav ne ciparu simboli
for (int i=0;i<b.length();i++){
    int a = b.at(i);
    if ((a>=48&&a<=57)||a==45){
        return 1;
    }
}
return 0;
}


int main()
{
    int n, b, first, next, skaits = 1, e, bignr;
    string nr;
    cout << "Cik buus skaitlju?" << endl;
    cin >> nr;
    while(!inputcheck(nr)){ ///ievadīto datu pārbaude un iespēja atkārtoti tos ievadīt
        cout<<"nepareizs datu tips, meegjini veelreiz"<<endl;
        cin>>nr;
    }
    stringstream g(nr); ///ievadīto datu pārveidošana int formā no string formas
    g>>n;
    if(n>0){ ///Pārbauda vai n ir naturāls skaitlis
    int m[n];

    cout << "Ievadi skaitljus:" << endl;
    for (int a=0; a<n; a++ ){ ///Masīva inicializēšana ar lietotāja ievadītiem datiem
        cin>>nr;
        if (!inputcheck(nr)){ ///ievadīto datu pārbaude un iespēja atkārtoti tos ievadīt
            cout<<"nepareizs datu tips! megjini atkal"<<endl;
            a--;
        }else {
            stringstream g(nr);///ievadīto datu pārveidošana int formā no string formas un to ievadīšana masīvā
            g>>b;
            m[a]=b;}
    }

    for (int f=n;f>1;f--){  ///Masīva kārtošana dilstošā secībā
        for (int c=0; c<(f-1); c++ ){
            first=m[c];
            next=m[(c+1)];
            if (first<next){
                m[c]=next;
                m[(c+1)]=first;
            }
       }
   }

   for(int i=0; i<n;i++){ ///lielākā skaitļa, kurš atkārtojas, noteikšana
    if (m[i]==m[(i+1)]){
        bignr=m[i];
        skaits++;
    }else if(skaits>1){
        e=i=999; ///izejas nosacījums
    }else skaits=1;
   }

   if(e==999){
    cout<<"Skaitlis "<<bignr<<" atkaartojas "<<skaits<<" reizes"<<endl;
   }else cout<<"skaitlji neakaartojas"<<endl;
    }else cout<<"Nepareizs datu tips"<<endl;

  ///cikliskuma iespējas nosacījums
  cout<<"Vai turpinaat (1) vai beigt (jebkursh cits simbols)?"<<'\n';
  int atb;
  cin>>atb;
  if(atb==1){
    main();
  }
}


