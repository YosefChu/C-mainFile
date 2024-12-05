#ifndef SYMBOLCOUNTS_H
#define SYMBOLCOUNTS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map> //hash table����Ϊhash table�Ĳ���ʱ�临�Ӷ�ΪO(1)������unordered_map�ǲ�������key�Ĵ�С�����
#include "Readtxt.h"
using namespace std;
// symbolCounts ��
// ���ߣ����Ȼ
// ѧ�ţ�202335550031
// ���ڣ�2023/11/17
// ******************PUBLIC OPERATIONS*********************
// void symbolCounts(const string &data, unordered_map<char, int> &hash_table)  --> ͳ���ַ����ֵĴ���
// void printCounts(unordered_map<char, int> hash_table)  --> ��ӡ�ַ����ֵĴ���
// **************************************************
// ʵ�� Huffman ���롢���롢ÿ���ַ���ƽ���ɱ����㹦��

// ���룺ʹ�����ɵı����滻ԭʼ�ı��е�ÿ���ַ�����������������ļ�

// ���룺���� Huffman ������ļ�������Ϊԭʼ�ı��ļ�

//(1)�ı�����Ƶ��ͳ�Ƶ�ʵ�� symbolCounts,ʹ��hash tableʵ��
void symbolCounts(string ch_data, unordered_map<char, int> &hash_table)//ͳ���ı���ÿ���ַ����ֵĴ�����ch_dataΪ�ı��ַ�����hash_tableΪhash table��unordered_map<char, int>��һ������Ϊ�ַ����ڶ�������Ϊ�ַ����ֵĴ���
{
    for (char ch : ch_data)//�����ַ����е�ÿһ���ַ���
    {
        hash_table[ch]++;//���hash_table�д�������ַ�����ô����ַ����ֵĴ�����1�����hash_table�в���������ַ�����ô��hash_table�в�������ַ�����������ַ����ֵĴ���Ϊ1
    }
}
void printCounts(unordered_map<char,int> hash_table)
{
    cout << "�ַ�Ƶ��ͳ��" << endl;
    for (auto it = hash_table.begin(); it != hash_table.end(); it++)
    {
        if (it->first == '\n')
        {
            cout << "\\n"
                 << ":" << it->second << endl;
        }
        else if (it->first == '\t')
        {
            cout << "\\t" << ":" << it->second << endl;
        }
        else if (it->first == ' ')
        {
            cout << "\"  \"" << ":" << it->second << endl;
        }
        else
        {
            cout << it->first << ":" << it->second << endl;
        }
    }
}
#endif
