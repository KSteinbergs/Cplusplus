#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct elem {
    int num;
    elem *next;
};

int input(){
    int i;
    cin>>i;
    if(cin.fail()) throw "failed";
    return i;
}

void add_element (elem*&first, elem*&last, int i)
{
    elem *p = new elem;
    p->num = i;
    p->next = NULL;
    if (first == NULL) first = p;
    else last->next = p;
    last = p;
}

void print_list (elem *first)
{
    for (elem *p = first; p!=NULL; p=p->next)
    {
        cout << p->num <<" ";
    }
    cout<<endl;
}

void delete_list (elem*&first)
{
    if (first==NULL) throw "list empty";
    elem *p = first;
    while (p!=NULL)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
///pārbauda vai nākošais elements ir liekāks par iepriekšējo satoties pēcoriģinālā saraksta
void check(elem *first){
    if (first==NULL) throw "list empty";
    elem *p = first;
    if(p->next==NULL)return;
    elem *l=first;
    elem *tmp; ///tiks izmantots lieko elemntu dzēšanai
    int previous=p->num;
    if(previous<(p->next)->num){
        previous=(p->next)->num;
        tmp=p->next;
        p->next=(p->next)->next;
        delete tmp;
    }else {
        previous=(p->next)->num;
        l=l->next;
        p=p->next;
    }
    for (p=p->next; (l->next)!=NULL;){
            //cout<<p->num<<" "<<(p->next)->num<<endl;
            //cout<<previous<<" "<<p->num<<endl;
            if (previous<p->num){
                previous=p->num;
                tmp=p;
                l->next=p->next;
                p=p->next;
                delete tmp;
            }else{
                previous=p->num;
                l=p;
                p=p->next;
            }
    }
}

///pārliek izveidoto sarakstu string formā
void listToOutfile(elem *first, string& outf){
    if (first==NULL) throw "list empty";
    for (elem *p = first; p!=NULL; p=p->next)
    {
        ostringstream oss; ///izmantots lai skaitli savienotu ar string
        oss<<outf<<p->num;
        outf=oss.str();
        outf= outf +' ';
    }
}

///Testa gadīumu pārbaudes funcija, kur file- ir inputs un x ir gadījuma nummurs
void tester(ifstream& file, int x){
    elem *first=NULL, *last=NULL, *p;
    int i;
    do{
        try {
            streambuf *cinbuf = cin.rdbuf(); ///saglabā veco bufferi
            cin.rdbuf(file.rdbuf()); ///redirecto faila datus uz cin
            i=input();
        }
        catch(const char *err) {
            cout<<err<<"-input was faulty, skipping it"<<endl;
            i=1;
            cin.clear(); ///ja ievade ir bijusi neveiksmīga iztīra cin un to ignorē
            cin.ignore();
            continue;
        }
        if(!cin.fail()&&i!=0){ ///pārbauda vai ievade ir bijusi veiksmīga (int)
            add_element (first, last, i);
        }
    }while (i != 0 &&file.peek()!=ifstream::traits_type::eof());
    string outf="";
    try{
        check(first);
        listToOutfile(first, outf);
        delete_list (first);
    }
    catch(const char *err) {
            cout<<err<<endl;
            //continue;
    }
    outf=outf+'0';
    ifstream awns;
    switch (x){ ///izvēlas pareizo atslēgas failu atkarībā no testa gadījuma
        case 1:
            awns.open("TestCases/awns1.txt");
            break;
        case 2:
            awns.open("TestCases/awns2.txt");
            break;
        case 3:
            awns.open("TestCases/awns3.txt");
            break;
        case 4:
            awns.open("TestCases/awns4.txt");
            break;
        case 5:
            awns.open("TestCases/awns5.txt");
            break;
        case 6:
            awns.open("TestCases/awns6.txt");
            break;
    }
    string correct="";
    while(getline(awns, correct)){
        if(outf != correct){
            cout<<"test nr "<<x<<" failed"<<endl;
            return;
        }
    }
    cout<<"test nr "<<x<<" Successful!"<<endl;
}






