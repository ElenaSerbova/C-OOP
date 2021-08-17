#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Contact
{
public:
    string name;
    string phone;
};

//ввод данных с клавиатуры
void InputNewContact(Contact& contact);

//сохраниение контакта в файл
void SaveContact(const Contact& contact);

//считывание всех контактов из файла
void ReadContacts();

int main()
{
    Contact contact;
    InputNewContact(contact);
    SaveContact(contact);
    ReadContacts();   
}

//ввод данных с клавиатуры
void InputNewContact(Contact& contact)
{
    cout << "Enter name: ";
    getline(cin, contact.name); //ввод строки с пробелами

    cout << "Enter phone: ";
    getline(cin, contact.phone);
}

//сохраниение контакта в файл
void SaveContact(const Contact& contact)
{
    //открываем файл для добавления в бинарном режиме
    //в первый раз он будет создаваться
    ofstream fout("Contacts.bin", ios::app | ios::binary);

    if (!fout.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    //если записывать объект типа string в вфайл,
    //то запишится лишь указатель, а не сами данные
    //при ситывании файла это приведет к ошибке этапа выполнения
    //т.к. считанный указатель будет битым
    //в файл нужно записывать сами данные

    //для того, чтобы при считывании знать сколько символов мы сохраняли
    //я в начале записываю в файл размер строки, учитывая ноль терминатор

    const char* name = contact.name.c_str();
    int sizeName = contact.name.size() + 1;

    const char* phone = contact.phone.c_str();
    int sizePhone = contact.phone.size() + 1;

    fout.write((char*)&sizeName, sizeof(int));
    fout.write(name, sizeName);

    fout.write((char*)&sizePhone, sizeof(int));
    fout.write(phone, sizePhone);

    fout.close();
}

void ReadContacts()
{
    ifstream fin("Contacts.bin", ios::in | ios::binary);

    if (!fin.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    //при считывании из файла, вначале я считываю размер строки
    //а затем саму строку

    while (!fin.eof())
    {
        int size;
        char name[255];
        char phone[255];

        fin.read((char*)&size, sizeof(int));
        fin.read(name, size);

        fin.read((char*)&size, sizeof(int));
        fin.read(phone, size);             

        if (fin.good())          //если считывание прошло успешно
        {
            Contact contact;     //создаем объект
            contact.name = name; //и записываем в него данные
            contact.phone = phone;

            cout << setw(15) << contact.name
                << setw(10) << contact.phone << endl;
        }
    }

    fin.close();
}
    
