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

//���� ������ � ����������
void InputNewContact(Contact& contact);

//����������� �������� � ����
void SaveContact(const Contact& contact);

//���������� ���� ��������� �� �����
void ReadContacts();

int main()
{
    Contact contact;
    InputNewContact(contact);
    SaveContact(contact);
    ReadContacts();   
}

//���� ������ � ����������
void InputNewContact(Contact& contact)
{
    cout << "Enter name: ";
    getline(cin, contact.name); //���� ������ � ���������

    cout << "Enter phone: ";
    getline(cin, contact.phone);
}

//����������� �������� � ����
void SaveContact(const Contact& contact)
{
    //��������� ���� ��� ���������� � �������� ������
    //� ������ ��� �� ����� �����������
    ofstream fout("Contacts.bin", ios::app | ios::binary);

    if (!fout.is_open())
    {
        cerr << "file not opened" << endl;
        return;
    }

    //���� ���������� ������ ���� string � �����,
    //�� ��������� ���� ���������, � �� ���� ������
    //��� ��������� ����� ��� �������� � ������ ����� ����������
    //�.�. ��������� ��������� ����� �����
    //� ���� ����� ���������� ���� ������

    //��� ����, ����� ��� ���������� ����� ������� �������� �� ���������
    //� � ������ ��������� � ���� ������ ������, �������� ���� ����������

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

    //��� ���������� �� �����, ������� � �������� ������ ������
    //� ����� ���� ������

    while (!fin.eof())
    {
        int size;
        char name[255];
        char phone[255];

        fin.read((char*)&size, sizeof(int));
        fin.read(name, size);

        fin.read((char*)&size, sizeof(int));
        fin.read(phone, size);             

        if (fin.good())          //���� ���������� ������ �������
        {
            Contact contact;     //������� ������
            contact.name = name; //� ���������� � ���� ������
            contact.phone = phone;

            cout << setw(15) << contact.name
                << setw(10) << contact.phone << endl;
        }
    }

    fin.close();
}
    
