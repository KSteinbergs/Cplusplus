#include <iostream>
#include <cmath>
using namespace std;

double doit(double x, double y, double z){
if (x>=z&&y>=z){
    return (x+y)/2;
}else if(x>=y&&z>=y){
    return (x+z)/2;
} else return (z+y)/2;
}
double dodo(int &x, int &y, double &z){
  z=(double)(x+y)/2;
  double tmp = x;
  x=y;
  y=tmp;
}
cdab(int N){
    int i=0, first, last, sk=N;
    while(N>0){
        if(i==0){
            last=N%10;
        }
        i++;
        if((N/10)==0){
            first=N%10;
        }
        N=N/10;
    }
    if(first>last){
        sk=(sk-(first*(pow(10,i-1))))/10;
    }
    cout<<sk;
}
int f(int N){
    int sk=N;
    if(N>9){
        int p=10, o=10, t=10, i=0;
        while(N/10!=0){
            i++;
            if (N/100==0){
                p=N/10; o=N%10;
            }
            if (N/1000==0&&N/100!=0){
                t=N%10;
            }
            N=N/10;
        }
        sk=sk-(p*pow(10,i))-(o*pow(10,i-1));
        if (t!=10){
            sk=sk-(t*pow(10,i-2))+(p*pow(10,i-2));
        }else sk=sk+(p*pow(10,i-1));
    }
    cout<<sk;
}
int exam(int n){
    int sk=n, first, last, ten=1;
    last = sk%10;
    while(sk>9){
        sk=sk/10;
        ten=ten*10;
        if(sk/10==0){
            first=sk%10;
        }
    }
    n=n-first*ten-last+first+last*ten;
    return n;
}
int prime(int a[], int n){
    for(int i=n;i>1;i--){
        for(int f=0; f<(i-1);f++){
            int first = a[f];
            int next = a[f+1];
            if(next<first){
                a[f]=next; a[f+1]=first;
            }
        }
    }
    cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
    int c=0;
    while(c<n){
            cout<<"!"<<endl;
        bool isPrime=true;

        for(int i=2; i<=a[c]/2;i++){
            if(a[c]%i==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime){return a[c];}
        c++;
    }
}


int main()
{
   int x[4]={42,47,7,63};
   cout<<x[0]<<x[1]<<x[2]<<x[3]<<endl;
   //double z;
    //cin>>x; //cin>>y; //cin>>z;
    //cout<<doit(x,y,z);
    //dodo(x,y,z);
    //cout<<z<<" "<<x<<" "<<y;
    //cdab(x);
    //f(x);
    cout<<prime(x,4);
}
