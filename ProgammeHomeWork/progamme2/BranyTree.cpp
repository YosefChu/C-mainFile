#include "infixToSuffix.h"
#include "UseSuffixToBulidABranyTree.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
/*
***********************************************************************
性名:朱浩然
班级:軟件工程4班
学号:202335550031
日期:2024/10/29
作业:programme2
说明:本程序是一个正则表达式转换为二叉树的程序，主要实现了中缀表达式转后缀表达式，后缀表达式构建二叉树，中序遍历二叉树，树形结构打印输出
且实现了判断输入的合法性，删除多余的双*号
用到多個文件，InfixToSuffix.h,UseSuffixToBulidABranyTree.h
infexToSuffix.h文件中实现了中缀表达式转后缀表达式，删除多余的双*号，判断输入的合法性
UseSuffixToBulidABranyTree.h文件中实现了后缀表达式构建二叉树，中序遍历二叉树，树形结构打印输出
***********************************************************************
*/
// 主函数
void test()
{
    string infix;
    while (1) // 循环
    {
        cout << "请输入中缀表达式: ";
        cin >> infix;
        if (infix == "exit")
        {
            break;
        }
        bool _bool = true;
        Determining_The_Legitimacy_Of_An_Input(infix, _bool); // 判断输入的合法性
        if (_bool)
        {
            complete(infix);                      // 補全隱含的連接符
            string suffix = InfixToSuffix(infix); // 中缀表达式转后缀表达式
            delete_star(suffix);
            TreeNode *root = buildTreeFromPostfix(suffix); // 用后缀表达式构建二叉树
            cout << "中序遍历结果: ";
            inorderTraversal(root); // 中序遍历二叉树
            cout << endl;
            cout << "树形结构打印输出: " << endl;
            printTree(root); // 树形结构打印输出
        }
    }
}
int main()
{
    test();
    return 0;
}