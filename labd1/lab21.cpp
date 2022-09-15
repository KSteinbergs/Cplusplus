#include <iostream>
using namespace std;

struct elem
{
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
};

void print_list (elem *first)
{
    for (elem *p = first; p!=NULL; p=p->next)
    {
        cout << p->num << endl;
    };
};

void delete_list (elem*&first)
{
    elem *p = first;
    while (p!=NULL)
    {
        first = first->next;
        delete p;
        p = first;
    };
}

int main ()
{
    elem *first=NULL, *last=NULL, *p;
    int i;
    cin >> i;
    while (i != 0)
    {
        add_element (first, last, i);
        cin >> i;
    };
    print_list (first);
    delete_list (first);
    return 0;
}
