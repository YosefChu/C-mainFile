#ifndef READTXT_H
#define READTXT_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
// Readtxt ��
// ���ߣ����Ȼ
// ѧ�ţ�202335550031
// ���ڣ�2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// void GetTxTData(const string &filename, string &data)  --> ���ı��ļ��ж�ȡ����
// void printTxtData(const string &filename)  --> ��ӡ�ı��ļ��е�����
// void BuildaBinaryFile(const string &Name)  --> ����һ���������ļ�
//void BuildaTxTFile(const string &Name)  --> ����һ��txt�ļ�
// void ReadStringToTxt(const string &Name, const string &data)  --> ���ַ���д��txt�ļ�
// void deleteFirstLine(const string &Name)  --> ɾ��txt�ļ��ĵ�һ��
// void deleteLastLine(const string &Name)  --> ɾ��txt�ļ������һ��
// ******************ERRORS********************************
// ����ļ�����ʧ�ܣ����������Ϣ������̨
// ݔ���ļ��r��һ������һ���Q�з��ģ�������Ҫ��ݔ���ļ���ɾ����һ��
void deleteFirstLine(const string &Name)
{
    ifstream fin(Name);
    if (!fin.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    string line;
    string data;
    int i = 0;
    while (getline(fin, line))
    {
        if (i != 0)
        {
            data += line + "\n";
        }
        i++;
    }
    fin.close();
    ofstream fout(Name);

    if (!fout.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    fout << data;
    fout.close();
}
// ����������ı����ݣ������ã����Ć��}���ı��ļ�������һ�Е����һ���Q�У�������Ҫ��ݔ���ı���ɾ�����һ��
void deleteLastLine(const string &Name)
{
    ifstream fin(Name);
    if (!fin.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    string line;
    string data;
    while (getline(fin, line))
    {
        data += line + "\n";
    }
    fin.close();
    data.erase(data.length() - 1);
    ofstream fout(Name);

    if (!fout.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    fout << data;
    fout.close();
}

void BuildaTxTFile(const string &Name) // ����һ��txt�ļ�
{
    string filename = Name;
    ifstream fin(filename);

    if (fin.is_open())
    {
        // cout << "�ļ��Ѿ�����:" << filename << endl;
    }
    else
    {
        ofstream fout(filename);

        if (fout.is_open())
        {
            cout << "�ļ������ɹ�:" << filename << endl;
            fout << "Hello World!" << endl;
            fout << "Hello C++!" << endl;
            fout << "Hello Vscode!" << endl;
            fout.close();
        }
        else
        {
            cout << "�ļ�����ʧ��:" << filename << endl;
        }
    }
}

void BuildaBinaryFile(const string &Name) // ����һ��Bin�ļ�
{
    string filename = Name;
    ifstream fin(filename,ios::binary);

    if (fin.is_open())
    {
        // cout << "�ļ��Ѿ�����:" << filename << endl;
    }
    else
    {
        ofstream fout(filename);
        if (fout.is_open())
        {
            cout << "�ļ������ɹ�:" << filename << endl;
            fout.close();
        }
        else
        {
            cout << "�ļ�����ʧ��:" << filename << endl;
        }
    }
}

void ReadStringToTxt(const string &Name, const string &data) // ���ַ���д��txt�ļ�
{
    ofstream fout(Name);

    if (!fout.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    fout << data;
    fout.close();
}

void GetTxTData(const string &FileName, string &data) // ��ȡtxt�ļ�����
{
    ifstream fin(FileName);
    if (!fin.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    string line;
    while (getline(fin, line))
    {
        data += line + "\n";
    }

    fin.close();
}

void printTxtData(const string &FileName) // ���txt�ļ�����
{
    ifstream fin(FileName);
    if (!fin.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    string line;
    while (getline(fin, line))//getline()������ȡ�ļ��е�һ��
    {
        cout << line << endl;//�����ȡ��һ�У�Ȼ���У�ʵ�����������������ļ���ȫ������
    }

    fin.close();
}
#endif // READTXT_H