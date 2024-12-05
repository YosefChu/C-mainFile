#ifndef BUILDHUFFMANBINARY_H
#define BUILDHUFFMANBINARY_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "HuffmanNode.h"
using namespace std;

// BuildHuffmanBinary 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// void serializeHuffmanTree(ofstream &fout, HuffmanNode *node)  --> 序列化 Huffman 树并写入二进制文件
// void saveHuffmanTree(const string &filename, HuffmanNode *root)  --> 序列化 Huffman 树并保存到指定的二进制文件中
// void writeEncodedData(const string &filename, const string &data)  --> 将编码后的数据写入二进制文件
// HuffmanNode* deserializeHuffmanTree(ifstream &fin)  --> 从二进制文件中反序列化 Huffman 树
// string readEncodedData(const string &filename)  --> 从二进制文件中读取编码后的数据
// ******************ERRORS********************************
// 如果文件操作失败，输出错误信息到控制台

// 将 Huffman 树序列化并写入二进制文件
void serializeHuffmanTree(ofstream &fout, HuffmanNode *node)
{
    if (node == nullptr)
    {
        fout.put('#'); // 用 '#' 表示空节点
        return;
    }
    fout.put(node->data);
    serializeHuffmanTree(fout, node->left);
    serializeHuffmanTree(fout, node->right);
}

// 将 Huffman 树序列化并保存到指定的二进制文件中
void saveHuffmanTree(const string &filename, HuffmanNode *root)
{
    ofstream fout(filename, ios::binary);
    if (!fout.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 序列化 Huffman 树
    serializeHuffmanTree(fout, root);

    fout.close();
}

// 将编码后的数据写入二进制文件
void writeEncodedData(const string &filename, const string &data)
{
    ofstream fout(filename,ios::binary);
    if (!fout.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 将编码后的数据打包成字节
    char byte = 0;
    int bitCount = 0;
    for (char bit : data)
    {
        byte = (byte << 1) | (bit - '0');
        bitCount++;
        if (bitCount == 8)
        {
            fout.write(&byte, 1);
            byte = 0;
            bitCount = 0;
        }
    }

    // 写入剩余的位
    if (bitCount > 0)
    {
        byte = byte << (8 - bitCount); // 左移填充剩余位
        fout.write(&byte, 1);
    }

    fout.close();
}

// 从二进制文件中反序列化 Huffman 树
HuffmanNode *deserializeHuffmanTree(ifstream &fin)
{
    char ch;
    fin.get(ch);
    if (ch == '#')
    {
        return nullptr;
    }
    HuffmanNode *node = new HuffmanNode(ch, 0);
    node->left = deserializeHuffmanTree(fin);
    node->right = deserializeHuffmanTree(fin);
    return node;
}

// 从二进制文件中读取编码后的数据
string readEncodedData(const string &filename)
{
    ifstream fin(filename, ios::binary);
    if (!fin.is_open())
    {
        cout << "文件打开失败" << endl;
        return "";
    }

    // 读取编码后的数据
    string encodedData;
    char byte;
    while (fin.read(&byte, 1))
    {
        for (int i = 7; i >= 0; --i)
        {
            encodedData += ((byte >> i) & 1) ? '1' : '0';
        }
    }

    fin.close();
    return encodedData;
}

#endif // BUILDHUFFMANBINARY_H