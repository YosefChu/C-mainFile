#ifndef SYMBOLCOUNTS_H
#define SYMBOLCOUNTS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map> //hash table，因为hash table的查找时间复杂度为O(1)，而且unordered_map是不會根據key的大小排序的
#include "Readtxt.h"
using namespace std;
// symbolCounts 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
// ******************PUBLIC OPERATIONS*********************
// void symbolCounts(const string &data, unordered_map<char, int> &hash_table)  --> 统计字符出现的次数
// void printCounts(unordered_map<char, int> hash_table)  --> 打印字符出现的次数
// **************************************************
// 实现 Huffman 编码、解码、每个字符的平均成本计算功能

// 编码：使用生成的编码替换原始文本中的每个字符，生成输出编码后的文件

// 解码：输入 Huffman 编码后文件，解码为原始文本文件

//(1)文本符号频次统计的实现 symbolCounts,使用hash table实现
void symbolCounts(string ch_data, unordered_map<char, int> &hash_table)//统计文本中每个字符出现的次数，ch_data为文本字符串，hash_table为hash table，unordered_map<char, int>第一个参数为字符，第二个参数为字符出现的次数
{
    for (char ch : ch_data)//遍历字符串中的每一个字符，
    {
        hash_table[ch]++;//如果hash_table中存在这个字符，那么这个字符出现的次数加1，如果hash_table中不存在这个字符，那么在hash_table中插入这个字符，并且这个字符出现的次数为1
    }
}
void printCounts(unordered_map<char,int> hash_table)
{
    cout << "字符频次统计" << endl;
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
