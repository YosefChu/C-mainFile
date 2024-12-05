#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
// HuffmanNode 类
// 作者：朱浩然
// 学号：202335550031
// 日期：2023/11/17
//
// ******************PUBLIC OPERATIONS*********************
// HuffmanNode()  --> 默认构造函数，初始化哈夫曼树的节点
// HuffmanNode(char _data, int _NumberOfCharacters)  --> 构造函数，初始化哈夫曼树的节点，包含字符和字符出现的次数

class HuffmanNode
{
public:
    char data;
    int NumberOfCharacters; // 字符出现的次数
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode()
    {
        data = 0;
        NumberOfCharacters = 0;
        left = nullptr;
        right = nullptr;
    }
    HuffmanNode(char _data, int _NumberOfCharacters) // 构造函数，初始化哈夫曼树的节点，哈夫曼树的节点包含字符，字符出现的次数，权重，左节点，右节点
    {
        data = _data;
        NumberOfCharacters = _NumberOfCharacters;
        left = nullptr;
        right = nullptr;
    }
};
#endif