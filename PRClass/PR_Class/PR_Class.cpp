#include <iostream>
#include<clocale>
#include"WorkStrClass.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите строки!\n";
    char a[1024];
    char b[1024];
    cin >> a;
    cin >> b;

    WorkStrClass ST(a);
    WorkStrClass ST2(b);
    cout << "Copying a part of a string =  " << ST.CopySt(2, 3)<<"\n";
    cout << "Deleting a part of a string =  " << ST.DeleteSt(2, 3) << "\n";
    cout << "String length =  " << ST.LengthStrok() << "\n";
    cout << ST << "\n";
    ST = ST + ST2;
    cout << "Concatenation of strings =  " << ST << "\n";
    cin >> a;
}