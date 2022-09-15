#include <iostream>

using namespace std;
/*******************************************

Kārlis Šteinbergs, ks19105

G7. Uzrakstīt funkciju, kas  izmet no saraksta tos elementus,
kuri lielāki par iepriekšējo (iepriekšējais elements ir tas, kurš norāda uz nākošo PIRMS izmešanas).

Programma izveidota: 2020/03/05

*******************************************/

struct elem {
    int num;
    elem *next;
};

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
    elem *p = first;
    while (p!=NULL)
    {
        first = first->next;
        delete p;
        cout<<"elem deleated"<<endl;
        p = first;
    }
}
///pārbauda vai nākošais elements ir liekāks par iepriekšējo glabājot iepriekšējā vērtību pirms izmešanas
void check(elem *first){
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

int main ()
{
    elem *first=NULL, *last=NULL, *p;
    int i;
    cout<<"Ievadiet saraksta elementus ar 0 ka beigu simbolu:";
    do{
        cin>>i;
        if(!cin.fail()&&i!=0){ ///pārbauda vai ievade ir bijusi veiksmīga (int)
            add_element (first, last, i);
        }else if (cin.fail()){
            i=1;
            cin.clear(); ///ja ievade ir bijusi neveiksmīga iztīra cin un to ignorē
            cin.ignore();
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
      }
    return 0;
}
