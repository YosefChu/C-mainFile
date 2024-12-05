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
// ����������Ҫͳ���ı���ÿ���ַ����ֵĴ�������������ʹ��hash table��ʵ�֣��ѳ��F�Δ����ٵăɂ��ַ��ρ��һ�����c���K�Ұ��@�ɂ����c�ĳ��F�Δ���ӣ�Ȼ���ٰ��@�����c�Żص�hash table�У�ֱ��hash table��ֻʣ��һ�����c��ֹ
// HuffmanCode_Codeing ��
// ���ߣ����Ȼ
// ѧ�ţ�202335550031
// ���ڣ�2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// void buildHuffmanTree(const string &inputFilename)  --> ���������ļ����� Huffman ��
// void encodeFile(const string &inputFilename, const string &outputFilename)  --> ���ļ����� Huffman ���벢������������ļ�
// void decodeFile(const string &inputFilename, const string &outputFilename)  --> �Զ������ļ����� Huffman ���벢������ı��ļ�
// ******************ERRORS********************************
// ����ļ�����ʧ�ܣ����������Ϣ������̨
/*
inputFilename: �����ļ���
outputFilename: ����ļ���
Hash table: ����ͳ���ı���ÿ���ַ����ֵĴ���
*&root: ���ڱ��湹����Huffman��
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
node: ��ǰ�ڵ�
hash_table: ���ڱ���ÿ���ַ���Huffman����
code: ��ǰ�ڵ��Huffman����
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
    // �ݹ����������������Ϊ0
    encodings(node->left, hash_table, code + "0");
    // �ݹ����������������Ϊ1
    encodings(node->right, hash_table, code + "1");
}
/*
hash_table: ���ڱ���ÿ���ַ���Huffman����
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