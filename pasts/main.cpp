#include <iostream>
#include <fstream>

using namespace std;

struct elem{
    int leng=0;
    char name[256]="";
    elem *next;
};

void delete_list (elem*&first)
{
    elem *p = first;
    while (p!=NULL)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void add_element (elem*&first, elem*&last, ifstream& file)
{
    if(file.peek()!=ifstream::traits_type::eof()){
        while(file.good()){
        char a;
        file.get(a);
        if(a!=' '&&a!='\n'&&a!='\t'){
            elem *p = new elem;
            int i=0;
            while(a!=' '&&a!='\n'&&a!='\t'&&!file.eof()){
                p->name[i]=a;
                i++;
                file.get(a);
            }
            //cout<<p->name;
            p->name[i]='\n';
            p->leng=i;
            p->next = NULL;
            if (first == NULL) first = last = p;
            else{
                char x=p->name[0];
                elem *b = first;
                bool xsmol=true;
                if(((int)x)<=90&&((int)x)>=65) xsmol=false;
                if((!xsmol&&((int)(b->name[0]))<=90&&((int)(b->name[0]))>=65)||(xsmol&&((int)(b->name[0]))<=122&&((int)(b->name[0]))>=97)){
                    if(((int)x)<=((int)(b->name[0]))){
                        p->next=first;
                        first=p;
                    }
                }else if(!xsmol&&((int)(b->name[0]))<=122&&((int)(b->name[0]))>=97){
                    if(((int)x)<=((int)(b->name[0])-32)){
                        p->next=first;
                        first=p;
                    }
                }else if(xsmol&&((int)(b->name[0]))<=90&&((int)(b->name[0]))>=65){
                    if(((int)x-32)<=((int)(b->name[0]))){
                        p->next=first;
                        first=p;
                    }
                }
                if(p!=first&&(first->next)!=NULL){
                    elem *c = first->next;
                    for (; c!=NULL; c=c->next){
                        bool bsmol=true;
                        if(((int)(b->name[0]))<=90&&((int)(b->name[0]))>=65) bsmol=false;
                        bool bcond=false;
                        if((int)x-(32*xsmol)>(int)(b->name[0])-(32*bsmol)) bcond=true;
                        if(bcond){
                            bool csmol=true;
                            if(((int)(c->name[0]))<=90&&((int)(c->name[0]))>=65) csmol=false;
                            if((int)x-(32*xsmol)<=(int)(c->name[0])-(32*csmol)){
                                    p->next=c;
                                    b->next=p;
                                    break;
                            }
                        }
                        b=b->next;
                    }
                    if(c==NULL){
                        p->next=c;
                        b->next=p;
                        last=p;
                    }
                }else if(p->next==NULL){
                    last->next = p;
                    last=p;
                }
            }
        }
        }
    }
}

void print_list (elem *first,ofstream& outf)
{
    for (elem *p = first; p!=NULL; p=p->next)
    {
        for(int i=0;i!=p->leng;i++){
            outf<<p->name[i];
            cout<<p->name[i];
        }
        if(p->next!=NULL){
        outf<<' ';
        cout<<' ';
        }
    }
    cout<<endl;
}



int main()
{
    ifstream file("pasts_test_win/post.i3");
    ofstream outf("out.txt");
    elem *first=NULL, *last=NULL, *p;
    add_element(first, last, file);
    if(first!=NULL){
    print_list (first,outf);
    delete_list (first);
    }else {
        cout<<"nothing";
        outf<<"nothing";
    }
    return 0;
}
