#include <iostream>
using namespace std;

int main()
{
    double d = 1.2346589;
    cout.fill ('-');
    cout.precision (3);
    cout.setf (ios::fixed);
    cout.width (7);
    cout.setf (ios::left);
    cout << d << "#" << endl;
    cout.unsetf (ios::fixed);
    cout.width (8);
    cout << d << "@" << endl;
    return 0;
}
