#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*******************************************

Kārlis Šteinbergs, ks19105

H1. Dots teksta fails. Atrast tekstā visbiežāk lietotos vārdus, kas sākas ar a, b, c utt. (katram latīņu alfabēta burtam, nešķirojot reģistru).
Programmai vārdi jāsaliek tabulā, kas realizēta kā vārdnīca (STL map), kur pēc pirmā burta glabājas visi vārdi, kas sākas ar šo burtu.
Vārdu saraksts, kas sākas ar doto burtu, arī ir vārdnīca, kas  katram vārdam glabā tā sastapto reižu skaitu tekstā. Programmas rezultātā
iegūt failu, kurā katram latīņu alfabēta burtam (a..z) izdrukāts biežāk sastopamais vārds un tā sastapšanas reižu skaits tekstā (piemēram,
and 101, but 18, captain 9 utt.). Par vārdu tiek uzskatīta latīņu alfabēta burtu virkne.

Programma izveidota: 2020/04/19

*******************************************/

void textToMap(ifstream& file, map<char,map<string,int> >& dic){
    string in="";
    bool wordst=false; ///tiks izmantots, lai pārbaudītu vai ir iesākts vārds
    if (file.is_open()){
        while(getline(file, in)){
            transform(in.begin(),in.end(),in.begin(),::tolower); ///pārvērš visus burtus stringā par lowercase
            string word="";
            for(int i=0; i<=((int)in.length());i++){
                    //cout<<in[i]<<"<---"<<endl;
                    if(((int)in[i])>=((int)'a')&&((int)in[i])<=((int)'z')){
                        wordst=true;
                        word=word+in[i];
                    }else if(wordst){
                        dic[word[0]][word]=dic[word[0]][word]+1;
                        wordst=false;
                        word="";
                    }
            }
        }
    }
}
///funkcia iet cauri map alfabēta secībā un atrod biežāk izmantoto vārdu un iekopē to (formatētā veidā) iekš izejas faila
void mapToFile( map<char,map<string,int> >& dic, ofstream& outf){
    for(int x = (int)'a';x<=(int)'z';x++){
        map<char,map<string,int> > ::iterator outerIt=dic.begin();
        map<string,int> ::iterator innerIt;
        map<char,map<string,int> > ::iterator seeker=dic.find((char)x); ///meklē vai mapā atrodas šis kāds vārds ar šo burtu
        string word="";
        char tmp=x;
        string out="";
        out=out+tmp;
        if(seeker!=dic.end()){
            int nr=0;
            for(innerIt=seeker->second.begin();innerIt!=seeker->second.end();innerIt++){
                if(innerIt->second > nr){
                    word=innerIt->first;
                    nr=innerIt->second;
                }
            }
            out=out+":"+word+"=";
            ostringstream oss; ///izmantots lai skaitli savienotu ar string
            oss<<out<<nr;
            out=oss.str();
        }else{
            out=out+": no words starting with this letter";
        }
        //cout<<out<<endl;
        outf<<out<<endl;
    }
}

int main()
{
    ifstream file("in.txt"); ///input
    ofstream outf("out.txt"); ///output
    map<char,map<string,int> > dictionary;
    textToMap(file,dictionary);
    mapToFile(dictionary,outf);
    ///izprintē map saturu uz konsoles
    /*map<char,map<string,int> > ::iterator outerIt=dictionary.begin();
    map<string,int> ::iterator innerIt;
    for(;outerIt!=dictionary.end();outerIt++){
        cout << outerIt->first << ":"<<endl;
        for(innerIt= outerIt->second.begin();innerIt!=outerIt->second.end();innerIt++){
            cout<<" "<<innerIt->first <<"="<<innerIt->second;
        }
        cout<<endl;
    }*/

    return 0;
}
