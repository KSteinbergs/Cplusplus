#include "SkMass.h"
#include <iostream>
#include "func.cpp"
#include <bits/stdc++.h>
using namespace std;


int main()
{
    SkMass first;
    first.Change(1,20);
    first.Change(2,0);
    first.Change(3,40);
    first.Change(0,10);
    cout<< fixed << setprecision(3)<<first.Sum(0,1)<<endl;
    cout<< fixed << setprecision(3)<<first.Avg()<<endl;
    SkMass second;
    second.Change(1,10);
    second.Change(4,10);
    cout<< fixed << setprecision(3)<<second.Avg()<<endl;
    second.Print();
    first.Print();
    first.Ini();
    first.Print();
    return 0;
}





