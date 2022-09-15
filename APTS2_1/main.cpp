#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;


int main()
{
    ifstream file("2016_new.txt");
    ofstream outf("out.txt");
    int ID, sk,x,y;
    string out="";
    string name[]={"Language and Social Studies, Scince, and Math","Social Studies and Language","Honors-college and university prep","Math, Volume 1","Math, Volume 2"};
    string base="insert into Pārdotais_Daudzums(Gads, Daudzums, Ģimeņu_Skaits, Reģ_ID, Nosaukums) values ('2019-09-01','";
    int daudz=42531;
    int fam=34523;
    for (int i=0;i<50;i++){
        file>>ID;
        file>>sk;
        out=base;
        if(i!=49){
        int in;
        //cout<<ID<<endl;
        //cin>>in;
        x=daudz*sk/100000;
        daudz=daudz-x;
        y=fam*sk/100000;
        fam=fam-y;
        }else{
            x=daudz;
            y=fam;
        }
        for(int j=0;j<5;j++){
            ostringstream oss;
            int tmpx = (x/7);
            int tmpy = (y/7);
            if(j<3){tmpx=tmpx;tmpy=tmpy;
            }else if(j==3){tmpx=tmpx*2;tmpy=tmpy*2;
            }else if(j==4){tmpx=x;tmpy=y;}
            x=x-tmpx;y=y-tmpy;
            oss<<base<<tmpx<<"','"<<tmpy<<"','"<<ID<<"','"<<name[j]<<"');";
            out=oss.str();
            outf<<out;
            outf<<'\n';
        }
    }
    /*for (int i=0;i<10;i++){
        file>>ID;
        file>>sk;
        out=base;
        ostringstream oss;
        oss<<out<<"6-01-01','"<<sk<<"','"<<ID<<"');";
        out=oss.str();
        outf<<out;
        outf<<'\n';
    }
    ifstream file2("2018.txt");
    for (int i=0;i<30;i++){
        file2>>ID;
        file2>>sk;
        out=base;
        int factor = rand() % 10 + 1;
        ostringstream oss;
        oss<<out<<"7-01-01','"<<sk-factor<<"','"<<ID<<"');";
        out=oss.str();
        outf<<out;
        outf<<'\n';
        out=base;
        ostringstream osss;
        osss<<out<<"8-01-01','"<<sk<<"','"<<ID<<"');";
        out=osss.str();
        outf<<out;
        outf<<'\n';
        out=base;
        ostringstream ossss;
        ossss<<out<<"9-01-01','"<<sk+factor<<"','"<<ID<<"');";
        out=ossss.str();
        outf<<out;
        outf<<'\n';
    }
    for (int i=0;i<10;i++){
        file2>>ID;
        file2>>sk;
        out=base;
        int factor = rand() % 10 + 1;
        ostringstream oss;
        oss<<out<<"8-01-01','"<<sk<<"','"<<ID<<"');";
        out=oss.str();
        outf<<out;
        outf<<'\n';
        out=base;
        ostringstream osss;
        osss<<out<<"9-01-01','"<<sk+factor<<"','"<<ID<<"');";
        out=osss.str();
        outf<<out;
        outf<<'\n';
    }
     for (int i=0;i<10;i++){
        file2>>ID;
        file2>>sk;
        out=base;
        ostringstream oss;
        oss<<out<<"9-01-01','"<<sk<<"','"<<ID<<"');";
        out=oss.str();
        outf<<out;
        outf<<'\n';
    }*/
    return 0;
}
