#include <iostream>
#include <iomanip>
using namespace std;

class ListElem{
public:
    int data;
    ListElem * next;
};

void addElemBack(ListElem*&first, ListElem*&last, int i){
    ListElem *p = new ListElem();
    p->data = i;
    p->next = 0;
    if(first==NULL){
            first=p;
    }else last->next = p;
    last=p;
}

void printList(ListElem*first){
    ListElem *curr = first;
    while(curr!=0){
        cout<<curr->data<<endl;
        curr = curr->next;
    }
}
void deleteList(ListElem*&first){
    ListElem *p = first;
    while(p!=0){
        first=first->next;
        delete p;
        p=first;
    }
}

void findByVal(ListElem*first,int val){
    ListElem *check=first;
    while(check!=0){
        if(check->data==val){return check;
        }else first = first->next;
    }
}

int main()
{
   ListElem * first = 0;
   ListElem * last = 0;
   addElemBack(first,last, 8);
   printList(first);
   return 0;
}
