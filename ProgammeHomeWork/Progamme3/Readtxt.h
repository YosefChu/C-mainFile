#ifndef READTXT_H
#define READTXT_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
// Readtxt 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// void GetTxTData(const string &filename, string &data)  --> 从文本文件中读取数据
// void printTxtData(const string &filename)  --> 打印文本文件中的数据
// void BuildaBinaryFile(const string &Name)  --> 创建一个二进制文件
//void BuildaTxTFile(const string &Name)  --> 创建一个txt文件
// void ReadStringToTxt(const string &Name, const string &data)  --> 将字符串写入txt文件
// void deleteFirstLine(const string &Name)  --> 删除txt文件的第一行
// void deleteLastLine(const string &Name)  --> 删除txt文件的最后一行
// ******************ERRORS********************************
// 如果文件操作失败，输出错误信息到控制台
// 輸入文件時第一行是有一個換行符的，所以需要在輸入文件後删除第一行
void deleteFirstLine(const string &Name)
{
    ifstream fin(Name);
    if (!fin.is_open())
    {
        cout << "文件打开失败" << endl;
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
        cout << "文件打开失败" << endl;
        return;
    }
    fout << data;
    fout.close();
}
// 输出解码后的文本内容，但應Ｃ＋＋的問題，文本文件中最後一行會多出一個換行，所以需要在輸出文本中删除最后一行
void deleteLastLine(const string &Name)
{
    ifstream fin(Name);
    if (!fin.is_open())
    {
        cout << "文件打开失败" << endl;
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
        cout << "文件打开失败" << endl;
        return;
    }
    fout << data;
    fout.close();
}

void BuildaTxTFile(const string &Name) // 创建一个txt文件
{
    string filename = Name;
    ifstream fin(filename);

    if (fin.is_open())
    {
        // cout << "文件已经存在:" << filename << endl;
    }
    else
    {
        ofstream fout(filename);

        if (fout.is_open())
        {
            cout << "文件创建成功:" << filename << endl;
            fout << "Hello World!" << endl;
            fout << "Hello C++!" << endl;
            fout << "Hello Vscode!" << endl;
            fout.close();
        }
        else
        {
            cout << "文件创建失败:" << filename << endl;
        }
    }
}

void BuildaBinaryFile(const string &Name) // 创建一个Bin文件
{
    string filename = Name;
    ifstream fin(filename,ios::binary);

    if (fin.is_open())
    {
        // cout << "文件已经存在:" << filename << endl;
    }
    else
    {
        ofstream fout(filename);
        if (fout.is_open())
        {
            cout << "文件创建成功:" << filename << endl;
            fout.close();
        }
        else
        {
            cout << "文件创建失败:" << filename << endl;
        }
    }
}

void ReadStringToTxt(const string &Name, const string &data) // 将字符串写入txt文件
{
    ofstream fout(Name);

    if (!fout.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    fout << data;
    fout.close();
}

void GetTxTData(const string &FileName, string &data) // 读取txt文件内容
{
    ifstream fin(FileName);
    if (!fin.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    string line;
    while (getline(fin, line))
    {
        data += line + "\n";
    }

    fin.close();
}

void printTxtData(const string &FileName) // 输出txt文件内容
{
    ifstream fin(FileName);
    if (!fin.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    string line;
    while (getline(fin, line))//getline()函数读取文件中的一行
    {
        cout << line << endl;//输出读取的一行，然后换行，实现逐行输出，即输出文件的全部内容
    }

    fin.close();
}
#endif // READTXT_H