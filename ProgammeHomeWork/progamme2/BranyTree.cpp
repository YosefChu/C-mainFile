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
����:���Ȼ
�༶:ܛ������4��
ѧ��:202335550031
����:2024/10/29
��ҵ:programme2
˵��:��������һ��������ʽת��Ϊ�������ĳ�����Ҫʵ������׺���ʽת��׺���ʽ����׺���ʽ������������������������������νṹ��ӡ���
��ʵ�����ж�����ĺϷ��ԣ�ɾ�������˫*��
�õ������ļ���InfixToSuffix.h,UseSuffixToBulidABranyTree.h
infexToSuffix.h�ļ���ʵ������׺���ʽת��׺���ʽ��ɾ�������˫*�ţ��ж�����ĺϷ���
UseSuffixToBulidABranyTree.h�ļ���ʵ���˺�׺���ʽ������������������������������νṹ��ӡ���
***********************************************************************
*/
// ������
void test()
{
    string infix;
    while (1) // ѭ��
    {
        cout << "��������׺���ʽ: ";
        cin >> infix;
        if (infix == "exit")
        {
            break;
        }
        bool _bool = true;
        Determining_The_Legitimacy_Of_An_Input(infix, _bool); // �ж�����ĺϷ���
        if (_bool)
        {
            complete(infix);                      // �aȫ�[�����B�ӷ�
            string suffix = InfixToSuffix(infix); // ��׺���ʽת��׺���ʽ
            delete_star(suffix);
            TreeNode *root = buildTreeFromPostfix(suffix); // �ú�׺���ʽ����������
            cout << "����������: ";
            inorderTraversal(root); // �������������
            cout << endl;
            cout << "���νṹ��ӡ���: " << endl;
            printTree(root); // ���νṹ��ӡ���
        }
    }
}
int main()
{
    test();
    return 0;
}