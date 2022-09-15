#include "SkMass.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

SkMass::SkMass(){
    this -> m[0] = 0.0;
    this -> m[1] = 0.0;
    this -> m[2] = 0.0;
    this -> m[3] = 0.0;
    this -> m[4] = 0.0;
}
void SkMass::Ini(){
    this -> m[0] = 0.0;
    this -> m[1] = 0.0;
    this -> m[2] = 0.0;
    this -> m[3] = 0.0;
    this -> m[4] = 0.0;
}
SkMass::~SkMass(){
    cout<<"Mass destroyed!";
}
void SkMass::Print(){cout << fixed << setprecision(3)<< m[0] <<" "<< m[1]<<" "<< m[2]<<" "<< m[3]<<" "<< m[4]<<endl;}

double SkMass::Sum(int sk1, int sk2){return m[sk1]+m[sk2];}

double SkMass::Avg(){
    int div=0;
    double sum=0;
    for(int i=0;i<5;i++){
        if(m[i]!=0){
            div++;
            sum+=m[i];
        }
    }
    return sum/div;
}

void SkMass::Change(int n, double sk){this -> m[n] = sk;}
