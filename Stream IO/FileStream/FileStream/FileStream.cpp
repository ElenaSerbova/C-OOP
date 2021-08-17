#include <iostream>
#include <fstream>
using namespace std;

void WriteTextFile();
void ReadTextFile();
void ReadNumbersFromFile();
void ReadWithErrors();
void ReadWithGetLine();
void ReadWithException();

int main()
{
   //WriteTextFile();
   //ReadTextFile();
   //ReadNumbersFromFile();
   //ReadWithErrors();
    ReadWithGetLine();
   //ReadWithException();
}

//absolute: C:/Test/text.txt
//relative: text.txt
//relative: data/text.txt
//relative: ./text.txt
//relative: ./data/text.txt
//relative: ../text.txt

void WriteTextFile()
{
    int a = 12;
    cout << "a = " << a << endl;

    ofstream fout;
    fout.open("test.txt");

    if (!fout.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    fout << "a = " << a << endl;

    fout.close();


}

void ReadTextFile()
{
    ifstream fin("test.txt");

    if (!fin.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    char buffer[255];
   
    /*fin >> buffer;
    cout << buffer << endl;*/

   /* fin.getline(buffer, 255);
    cout << buffer << endl;*/

    char simb = fin.get();
    cout << simb << endl;
    

    fin.close();
}

void ReadNumbersFromFile()
{
    ifstream fin("numbers.txt");

    if (!fin.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    int arr[5];

    for (size_t i = 0; i < 5; i++)
    {
        fin >> arr[i];

        cout << arr[i] << endl;
    }

    fin.close();
}

void PrintState(const ios& stream)
{
    int state = stream.rdstate();

    if ((state & ios::badbit) != 0)
    {
        cout << "bad" << endl;
    }
    else if ((state & ios::failbit) != 0)
    {
        cout << "fail" << endl;
    }
    else if ((state & ios::eofbit) != 0)
    {
        cout << "eof" << endl;
    }
    else {
        cout << "good" << endl;
    }
}

void ReadWithErrors()
{
    ifstream fin("test.txt");

    if (!fin.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    int a;

    while (!fin.eof())
    {

        fin >> a;        

        if (!fin.good())
        {
            PrintState(fin);            
            
            fin.clear();
            fin.ignore(1);
           
            PrintState(fin);
        }
        else
        {
            cout << a << endl;
        }
    }
    

    fin.close();
}

void ReadWithGetLine()
{
    ifstream fin("Text.txt");

    if (!fin.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    char buffer[1024];

    while (!fin.eof())
    {
        fin.getline(buffer, 1024);

        cout << buffer << endl;
    }

    fin.close();
}

void ReadWithException()
{
    ifstream fin("test.txt");

    if (!fin.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    fin.exceptions(ios::failbit | ios::badbit);

    int a;

    while (!fin.eof())
    {
        try {

            fin >> a;
            cout << a << endl;
        }
        catch (const ios::failure& ex)
        {
            cout << ex.what() << endl;
            fin.clear();
            fin.ignore(1);
        }  
    }


    fin.close();
}
