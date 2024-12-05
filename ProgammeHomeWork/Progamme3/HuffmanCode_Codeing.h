#ifndef HUFFMANCODE_CODEING_H
#define HUFFMANCODE_CODEING_H
#include "Readtxt.h"
#include "symbolCounts.h"
#include "MinHeap.h"
#include "HuffmanNode.h"
#include"BuildHuffmanBinary.h"
#include <iomanip>
#include <iostream>
using namespace std;
// 首先我们需要统计文本中每个字符出现的次数，这里我们使用hash table来实现，把出現次數最少的兩個字符合併成一個節點，並且把這兩個節點的出現次數相加，然後再把這個節點放回到hash table中，直到hash table中只剩下一個節點為止
// HuffmanCode_Codeing 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// void buildHuffmanTree(const string &inputFilename)  --> 根据输入文件构建 Huffman 树
// void encodeFile(const string &inputFilename, const string &outputFilename)  --> 对文件进行 Huffman 编码并输出到二进制文件
// void decodeFile(const string &inputFilename, const string &outputFilename)  --> 对二进制文件进行 Huffman 解码并输出到文本文件
// ******************ERRORS********************************
// 如果文件操作失败，输出错误信息到控制台
/*
inputFilename: 输入文件名
outputFilename: 输出文件名
Hash table: 用于统计文本中每个字符出现的次数
*&root: 用于保存构建的Huffman树
*/
void buildHummantree(unordered_map<char, int> &hash_table, HuffmanNode * &root)
{
    int n = hash_table.size();
    Minheap minHeap(n);
    for (auto it = hash_table.begin(); it != hash_table.end(); it++)
    {
        HuffmanNode node(it->first, it->second);
        minHeap.insert(node);
    }
    while (minHeap.getSize() > 1)
    {
        HuffmanNode left = minHeap.TakeHuffmanNodeMinNumberOfCharacters();
        HuffmanNode right = minHeap.TakeHuffmanNodeMinNumberOfCharacters();
        HuffmanNode parent(0, left.NumberOfCharacters + right.NumberOfCharacters);
        parent.left = new HuffmanNode(left);
        parent.right = new HuffmanNode(right);
        minHeap.insert(parent);
    }
    root = new HuffmanNode(minHeap.TakeHuffmanNodeMinNumberOfCharacters());
}
/*
node: 当前节点
hash_table: 用于保存每个字符的Huffman编码
code: 当前节点的Huffman编码
*/
void encodings(HuffmanNode *node, unordered_map<char, string> &hash_table, string code)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->left == nullptr && node->right == nullptr)
    {
        hash_table[node->data] = code;
        return;
    }
    // 递归遍历左子树，编码为0
    encodings(node->left, hash_table, code + "0");
    // 递归遍历右子树，编码为1
    encodings(node->right, hash_table, code + "1");
}
/*
hash_table: 用于保存每个字符的Huffman编码
*/
void printEncodings(unordered_map<char, string> hash_table)
{
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
        else if (isprint(it->first))
        {
            cout << it->first << ":" << it->second << endl;
        }
        else
        {
            cout << "\\x" << hex << setw(2) << setfill('0') << (int)(unsigned char)it->first << ":" << it->second << endl;
        }
    }
}
#endif