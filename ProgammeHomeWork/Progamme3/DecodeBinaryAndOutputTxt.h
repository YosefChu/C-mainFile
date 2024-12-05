#ifndef DECODEBINARYANDOUTPUTTXT_H
#define DECODEBINARYANDOUTPUTTXT_H

#include <iostream>
#include <fstream>
#include <string>
#include "HuffmanNode.h"
#include "BuildHuffmanBinary.h"
using namespace std;

// DecodeBinaryAndOutputTxt 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// void decodeBinaryAndOutputTxt(const string &treeFilename, const string &dataFilename, const string &outputFilename)  --> 解码二进制数据并输出到文本文件
// ******************ERRORS********************************
// 如果文件操作失败，输出错误信息到控制台

// 解码二进制数据并输出到文本文件
/*
treeFilename: 保存 Huffman 树的二进制文件名
dataFilename: 保存编码后的数据的二进制文件名
outputFilename: 输出解码后的文本文件名
*/
void decodeBinaryAndOutputTxt(const string &treeFilename, const string &dataFilename, const string &outputFilename)
{
    // 反序列化 Huffman 树
    ifstream treeFile(treeFilename,ios::binary);
    if (!treeFile.is_open())
    {
        cout << "文件打开失败: " << treeFilename << endl;
        return;
    }
    HuffmanNode *root = deserializeHuffmanTree(treeFile);
    treeFile.close();

    if (root == nullptr)
    {
        cout << "反序列化 Huffman 树失败" << endl;
        return;
    }

    // 读取编码后的数据
    string encodedData = readEncodedData(dataFilename);

    // 解码数据
    string decodedData;
    HuffmanNode *current = root;
    for (char bit : encodedData)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        // 如果到达叶子节点，输出字符并重置当前节点
        if (current->left == nullptr && current->right == nullptr)
        {
            decodedData += current->data;
            current = root;
        }
    }

    // 输出解码后的文本到文件
    ofstream fout(outputFilename);
    if (!fout.is_open())
    {
        cout << "文件打开失败: " << outputFilename << endl;
        return;
    }
    fout << decodedData;
    fout.close();

    // 清理 Huffman 树
    delete root;
}

#endif // DECODEBINARYANDOUTPUTTXT_H