#ifndef READANDBUILDFILE_H
#define READANDBUILDFILE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void Input_Read_ObtainFileFailure(const string &filename) // 當文件不存在则创建
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cout << "文件不存在或是查找失敗，是否創造該＂" << filename << "＂文件在該目錄下" << endl;
        cout << "輸入Y創造該文件，輸入N退出" << endl;
        char ch;
        cin >> ch;
        if(ch=='Y'||ch=='y')
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
        else
        {
            exit(0);
        }
    }
}
void BuildaTxTFile(const std::string &FileName) // 创建一个txt文件
{
    ifstream fin(FileName);
    if (fin.is_open())
    {
        cout << "文件已经存在:" << FileName << endl;
    }
    else
    {
        ofstream fout(FileName);
        if (fout.is_open())
        {
            cout << "文件创建成功:" << FileName << endl;
            fout.close();
        }
        else
        {
            cout << "文件创建失败:" << FileName << endl;
        }
    }
}
void BuildaBinaryFile(const string &FileName) // 创建一个二进制文件
{
    ifstream fin(FileName);
    if (fin.is_open())
    {
        cout << "文件已经存在:" << FileName << endl;
    }
    else
    {
        ofstream fout(FileName, ios::binary);
        if (fout.is_open())
        {
            cout << "文件创建成功:" << FileName << endl;
            fout.close();
        }
        else
        {
            cout << "文件创建失败:" << FileName << endl;
        }
    }
}
void GetFileData(const string &FileName) // 获取文件数据
{
    ifstream fin(FileName);
    if (fin.is_open())
    {
        string data;
        while (getline(fin, data))
        {
            cout << data << endl;
        }
        fin.close();
    }
    else
    {
        Input_Read_ObtainFileFailure(FileName);
    }
}
void ReadStringToTxt(const string &FileName, const string &data) // 将字符串写入txt文件
{
    ofstream fout(FileName);
    if (!fout.is_open())
    {
       Input_Read_ObtainFileFailure(FileName);
       return;
    }
    fout << data;
    fout.close();
}
#endif // READANDBUILDFILE_H