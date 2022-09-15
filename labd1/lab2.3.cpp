#include <iostream>
using namespace std;

int main()
{
    double d = 987;
    cout << "Input numeric value #1" << endl;
	cin >> d;
    cout << "Output: " << d << endl;
    if (!cin.good())

    {

        cin.clear();

        cin.ignore (1, '\n');

    };
    cout << "Input numeric value #2" << endl;
	cin >> d;
    cout << "Output: " << d << endl;
    return 0;
}
