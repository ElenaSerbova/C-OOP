#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void SetPrecision()
{  
    auto precision = cout.precision();
    cout << "precision: " << precision << endl;

    cout.precision(7);

    precision = cout.precision();
    cout << "precision: " << precision << endl;

    double d = 12.123456789;

    cout << "d: " << d << endl;

    d = 1.123456789;

    cout << "d: " << d << endl;

    d = 123.123456789;

    cout << "d: " << d << endl;
}
void SetWidth() {
    auto width = cout.width();
    cout << "width: " << width << endl;

    cout.width(10);
    cout << 12;

    cout.width(10);
    cout << 15 << endl;

    cout.width(10);
    cout << 134;

    cout.width(10);
    cout << 14 << endl;

    cout.width(10);
    cout.fill('.');
    cout << "width" << endl;

    cout.width(10);
    cout << "The first form (1) returns the current value of the field width." << endl;

}
void SetFlags() {

    cout.flags( ios::hex );
    cout <<"HEX: " << 123 << endl;

    cout.flags(ios::oct);
    cout << "OCT: " << 123 << endl;

    cout.flags(ios::dec);
    cout << "DEC: " << 123 << endl;


    cout.flags(ios::hex | ios::showbase);
    cout << "HEX: " << 123 << endl;

    cout.flags(ios::oct | ios::showbase);
    cout << "OCT: " << 123 << endl;

    cout.flags(ios::dec | ios::showbase);
    cout << "DEC: " << 123 << endl;


    cout.flags(ios::scientific);
    cout << "Scientific: " << 123.234 << endl;

    cout.flags(ios::fixed);
    cout << "Fixed: " << 123.234 << endl;

    cout.unsetf(ios::fixed);
    cout << "Unset: " << 123.234 << endl;

    cout.width(10);
    cout.flags(ios::left);

    cout << "Text" << "Tratata" << endl;

    cout.width(10);
    cout.flags(ios::right);

    cout << "Text" << "Tratata" << endl;

    cout.unsetf(ios::left);
}
void Manipulators() {

    cout << setprecision(10) << 10.1234546789 << endl;
    cout << 12.234345345456 << endl;

    cout << setw(10) << setfill('.') << "hello" << endl;
    cout << setw(10) << setfill('.') << left << "world" << endl;

    cout << hex << "HEX: " << 123 << endl;
    cout << oct << "OCT: " << 123 << endl;
    cout << dec << "DEC: " << 123 << endl;
}

struct Student {
    string fio;
    int marks[5];
};

void CreateFile(){

    Student students[3] = {
        {"Jhon Snow", {12, 10, 11, 9, 11}},
        {"Aria Stark", {8, 10, 8, 9, 11}},
        {"Sansa Stark", {9, 11, 11, 9, 11}}
    };

    ofstream fout("test.txt");

    if (!fout.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    for (size_t i = 0; i < 3; i++)
    {
        fout << setw(15) << left << students[i].fio;
        fout << right;
        for (size_t j = 0; j < 5; j++)
        {
            fout << setw(5) << students[i].marks[j];
        }

        fout << endl;

        fout << setw(41) << setfill('-') << "" << endl << setfill(' ');
    }

    fout.close();

}

int main()
{
   //SetPrecision();
   //SetWidth();
   // SetFlags();
   // Manipulators();
    CreateFile();
}
 