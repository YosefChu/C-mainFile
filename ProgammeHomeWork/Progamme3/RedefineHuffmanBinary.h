#ifndef REDEFINEHUFFMANBINARY_H
#define REDEFINEHUFFMANBINARY_H
#include <iostream>
#include <fstream>
#include "BuildHuffmanBinary.h"
#include "HuffmanNode.h"
using namespace std;
// 解码：输入 Huffman 编码后文件，解码为原始文本文件
// RedefineHuffmanBinary 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
// ******************PUBLIC OPERATIONS*********************
// void decodeHuffmanTree(ifstream &fin, HuffmanNode *&node)  --> 解码 Huffman 树
void decodeHuffmanTree(ifstream &fin, HuffmanNode *&node)
{
    char ch;
    fin.get(ch);
    if (ch == '#')
    {
        node = nullptr;
        return;
    }
    node = new HuffmanNode(ch, 0);
    decodeHuffmanTree(fin, node->left);
    decodeHuffmanTree(fin, node->right);
}



#endif