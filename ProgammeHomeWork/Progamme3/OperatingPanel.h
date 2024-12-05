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

// OperatingPanel ��
// ���ߣ����Ȼ
// ѧ�ţ�202335550031
// ���ڣ�2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// void OpenSystem()  --> ִ��һϵ�в������������롢����ͼ���ѹ����
// ******************ERRORS********************************
// ����ļ�����ʧ�ܣ����������Ϣ������̨
void GetInput(string &ch_data)
{
    cout << "Ոݔ���ı����� (�� Ctrl+Z �Y��ݔ��):" << endl;
    char ch;
    while (cin.get(ch))
    {
        if (ch == 26) // ASCII �� 26 ��Ӧ Ctrl+Z
        {
            break;
        }
        ch_data += ch;
    }
}
void OpenSystem()
{
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "                   �ı��ļ�ͨ�^HuffmanCode���s�c�≺�sϵ�y                   " << endl;
    cout << "�Ƿ�ʹ��Ĭ�J�ı��ļ��M�Љ��s�c�≺�s?(Ŀǰֻ֧��Ӣ��)" << endl
         << "Y/N (���� 'exit' �˳�)" << endl;
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
             << "ÿ���ַ���Huffman���a" << endl;
        printEncodings(HuffmanCode);
        /////////////////////////////////
        string encodedData;
        for (char ch : ch_data)
        {
            encodedData += HuffmanCode[ch];
        }
        // ������������д��������ļ�
        writeEncodedData("encoded.bin", encodedData);
        // ���� Huffman �����������ļ�
        saveHuffmanTree("huffman_tree.bin", root);
        // �Ӷ������ļ��ж�ȡ���������ݲ�����
        decodeBinaryAndOutputTxt("huffman_tree.bin", "encoded.bin", "decoded.txt");
        // ��ȡ�������ı�����
        string decodedText;
        GetTxTData("decoded.txt", decodedText);
        cout << endl
             << "�������ı�����: " << endl
             << decodedText << endl;
        // ����ѹ����
        double compressionRate = calculateCompressionRate("originalTxT.txt", "encoded.bin");
        if (compressionRate != -1)
        {
            cout << "ѹ����: " << compressionRate << "%" << endl;
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
             << "ÿ���ַ���Huffman���a" << endl;
        printEncodings(HuffmanCode);
        /////////////////////////////////
        string encodedData;
        for (char ch : ch_data)
        {
            encodedData += HuffmanCode[ch];
        }
        // ������������д��������ļ�
        writeEncodedData("Userencoded.bin", encodedData);
        // ���� Huffman �����������ļ�
        saveHuffmanTree("user_huffman_tree.bin", root);
        // �Ӷ������ļ��ж�ȡ���������ݲ�����
        decodeBinaryAndOutputTxt("user_huffman_tree.bin", "Userencoded.bin", "Userdecoded.txt");
        // ��ȡ�������ı�����
        string decodedText;
        GetTxTData("Userdecoded.txt", decodedText);
        cout << endl
             << "�������ı�����: " << endl
             << decodedText << endl;
        // ����ѹ����
        double compressionRate = calculateCompressionRate("UseroriginalTxT.txt", "Userencoded.bin");
        if (compressionRate != -1)
        {
            cout << "ѹ����: " << compressionRate << "%" << endl;
        }
    }
    else
    {
        cout << "��Ч��ѡ�������� 'Y' �� 'N'�������� 'exit' �˳���" << endl;
    }
}

#endif // OPERATINGPANEL_H