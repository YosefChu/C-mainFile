#ifndef OPERATINGPANEL_H
#define OPERATINGPANEL_H
#include <iostream>
#include <fstream>
#include "BuildHuffmanBinary.h"
#include "HuffmanNode.h"
#include "DecodeBinaryAndOutputTxt.h"
#include "Readtxt.h"
#include "HuffmanCode_Codeing.h"
#include "symbolCounts.h"
#include "MinHeap.h"
#include "CompressionRate.h"
using namespace std;

// OperatingPanel 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// void OpenSystem()  --> 执行一系列操作，包括编码、解码和计算压缩率
// ******************ERRORS********************************
// 如果文件操作失败，输出错误信息到控制台
void GetInput(string &ch_data)
{
    cout << "請輸入文本內容 (按 Ctrl+Z 結束輸入):" << endl;
    char ch;
    while (cin.get(ch))
    {
        if (ch == 26) // ASCII 码 26 对应 Ctrl+Z
        {
            break;
        }
        ch_data += ch;
    }
}
void OpenSystem()
{
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "                   文本文件通過HuffmanCode壓縮與解壓縮系統                   " << endl;
    cout << "是否使用默認文本文件進行壓縮與解壓縮?(目前只支持英文)" << endl
         << "Y/N (输入 'exit' 退出)" << endl;
    string choice;
    cin >> choice;
    if (choice == "Y")
    {
        string ch_data;
        unordered_map<char, int> hash_table;
        BuildaTxTFile("originalTxT.txt");
        GetTxTData("originalTxT.txt", ch_data);
        printTxtData("originalTxT.txt");
        /////////////////////////////////
        symbolCounts(ch_data, hash_table);
        printCounts(hash_table);
        /////////////////////////////////
        HuffmanNode *root = nullptr;
        buildHummantree(hash_table, root);
        /////////////////////////////////
        unordered_map<char, string> HuffmanCode;
        encodings(root, HuffmanCode, "");
        cout << endl
             << "每個字符的Huffman編碼" << endl;
        printEncodings(HuffmanCode);
        /////////////////////////////////
        string encodedData;
        for (char ch : ch_data)
        {
            encodedData += HuffmanCode[ch];
        }
        // 将编码后的数据写入二进制文件
        writeEncodedData("encoded.bin", encodedData);
        // 保存 Huffman 树到二进制文件
        saveHuffmanTree("huffman_tree.bin", root);
        // 从二进制文件中读取编码后的数据并解码
        decodeBinaryAndOutputTxt("huffman_tree.bin", "encoded.bin", "decoded.txt");
        // 读取解码后的文本内容
        string decodedText;
        GetTxTData("decoded.txt", decodedText);
        cout << endl
             << "解码后的文本内容: " << endl
             << decodedText << endl;
        // 计算压缩率
        double compressionRate = calculateCompressionRate("originalTxT.txt", "encoded.bin");
        if (compressionRate != -1)
        {
            cout << "压缩率: " << compressionRate << "%" << endl;
        }
    }
    else if (choice == "N")
    {
        unordered_map<char, int> hash_table;
        string ch_data;
        GetInput(ch_data);
        BuildaTxTFile("UseroriginalTxT.txt");
        ReadStringToTxt("UseroriginalTxT.txt", ch_data);
        deleteFirstLine("UseroriginalTxT.txt");
        deleteLastLine("UseroriginalTxT.txt");
        /////////////////////////////////
        symbolCounts(ch_data, hash_table);
        printCounts(hash_table);
        /////////////////////////////////
        HuffmanNode *root = nullptr;
        buildHummantree(hash_table, root);
        /////////////////////////////////
        unordered_map<char, string> HuffmanCode;
        encodings(root, HuffmanCode, "");
        cout << endl
             << "每個字符的Huffman編碼" << endl;
        printEncodings(HuffmanCode);
        /////////////////////////////////
        string encodedData;
        for (char ch : ch_data)
        {
            encodedData += HuffmanCode[ch];
        }
        // 将编码后的数据写入二进制文件
        writeEncodedData("Userencoded.bin", encodedData);
        // 保存 Huffman 树到二进制文件
        saveHuffmanTree("user_huffman_tree.bin", root);
        // 从二进制文件中读取编码后的数据并解码
        decodeBinaryAndOutputTxt("user_huffman_tree.bin", "Userencoded.bin", "Userdecoded.txt");
        // 读取解码后的文本内容
        string decodedText;
        GetTxTData("Userdecoded.txt", decodedText);
        cout << endl
             << "解码后的文本内容: " << endl
             << decodedText << endl;
        // 计算压缩率
        double compressionRate = calculateCompressionRate("UseroriginalTxT.txt", "Userencoded.bin");
        if (compressionRate != -1)
        {
            cout << "压缩率: " << compressionRate << "%" << endl;
        }
    }
    else
    {
        cout << "无效的选择，请输入 'Y' 或 'N'，或输入 'exit' 退出。" << endl;
    }
}

#endif // OPERATINGPANEL_H