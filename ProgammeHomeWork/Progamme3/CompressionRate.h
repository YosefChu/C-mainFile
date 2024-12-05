#ifndef COMPRESSIONRATE_H
#define COMPRESSIONRATE_H

#include <iostream>
#include <fstream>
using namespace std;
// CompressionRate 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// long getFileSize(const string &filename)  --> 获取文件大小
// double calculateCompressionRate(const string &originalFile, const string &compressedFile)  --> 计算压缩率
// ******************ERRORS********************************
// 如果文件操作失败，输出错误信息到控制台

// 获取文件大小
long getFileSize(const string &filename)
{
    ifstream file(filename, ios::binary | ios::ate);
    if (!file.is_open())
    {
        cout << "文件打开失败: " << filename << endl;
        return -1;
    }
    long fileSize = file.tellg();
    file.close();
    return fileSize;
}

// 计算压缩率
double calculateCompressionRate(const string &originalFile, const string &compressedFile)
{
    long originalSize = getFileSize(originalFile);
    long compressedSize = getFileSize(compressedFile);

    if (originalSize == -1 || compressedSize == -1)
    {
        return -1;
    }

    double compressionRate = (1.0 - (double)compressedSize / originalSize) * 100;
    return compressionRate;
}

#endif // COMPRESSIONRATE_H