#ifndef USESUFFIXTOBULIDABRANYTREE_H
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
// ����������ڵ�
/*
0. Ҷ�ӽڵ�
1. Concatenation
2. Union
3. Kleene �հ�
*/
class TreeNode// ����������ڵ�
{
public:
    char data;// ����
    TreeNode *left;  // ������
    TreeNode *right; // ������
    TreeNode(char _data)// ���캯��
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
};
// �ú�׺���ʽ����������
/*
1. �����ַ���
2. �������ĸ��ѹ��ջ��
3. �����*������ջ��Ԫ�أ���Ϊ������������һ���µĽڵ㣬��Ϊ���ڵ㣬ջ��Ԫ����Ϊ��������ѹ��ջ��
4. �����|������ջ��Ԫ�أ���Ϊ������������ջ��Ԫ�أ���Ϊ������������һ���µĽڵ㣬��Ϊ���ڵ㣬ѹ��ջ��
5. �����-������ջ��Ԫ�أ���Ϊ������������ջ��Ԫ�أ���Ϊ������������һ���µĽڵ㣬��Ϊ���ڵ㣬ѹ��ջ��
*/
TreeNode *buildTreeFromPostfix(const string str)// �ú�׺���ʽ����������
{
    int length = str.size();// �ַ����ĳ���
    stack<TreeNode *> letter;// ��ĸջ
    for (int i = 0; i < length; i++)// �����ַ���
    {
        TreeNode *node = new TreeNode(str[i]);// �½�һ���ڵ�
        if (isalpha(str[i]))// �������ĸ
        {
            letter.push(node);// ѹ��ջ��
        }
        else if (str[i] == '*')// ����Ǳհ�����
        {
            TreeNode *root = new TreeNode('*');// �½�һ���ڵ�
            root->right = letter.top();// ����ջ��Ԫ�أ���Ϊ������
            letter.pop();// ����ջ��Ԫ��
            letter.push(root);// ѹ��ջ��
        }
        else if (str[i] == '|')// ����ǻ����
        {
            TreeNode *root = new TreeNode('|');// �½�һ���ڵ�
            root->right = letter.top();// ����ջ��Ԫ�أ���Ϊ������
            letter.pop();// ����ջ��Ԫ��
            root->left = letter.top();// ����ջ��Ԫ�أ���Ϊ������
            letter.pop();// ����ջ��Ԫ��
            letter.push(root);// ѹ��ջ��
        }
        else if (str[i] == '-')// ��������ӷ���
        {
            TreeNode *root = new TreeNode('-');// �½�һ���ڵ�
            root->right = letter.top();// ����ջ��Ԫ�أ���Ϊ������
            letter.pop();// ����ջ��Ԫ��
            root->left = letter.top();// ����ջ��Ԫ�أ���Ϊ������
            letter.pop();// ����ջ��Ԫ��
            letter.push(root);// ѹ��ջ��
        }
    }
    return letter.top();// ����ջ��Ԫ��
}
// �������������
/*
1. ������ڵ㲻Ϊ��
2. �ݹ����������
3. ������ڵ�
4. �ݹ����������
5.������ڵ�
*/
void inorderTraversal(TreeNode *root)// �������������
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
// ��ȡ�ڵ�����
/*
0. Ҷ�ӽڵ�
1. Concatenation
2. Union
3. Kleene �հ�
-1. δ֪����
*/
int getNodeType(char data)
{
    if (isalpha(data))
        return 0; // Ҷ�ӽڵ�
    if (data == '-')
        return 1; // Concatenation
    if (data == '|')
        return 2; // Union
    if (data == '*')
        return 3; // Kleene �հ�
    return -1;    // δ֪����
}
//�،�ݔ��������˹��c���ӹ��c���tݔ���ӹ��c
/*
1. �����������Ϊ�գ����������
2. �����������Ϊ�գ����������
*/
void elementprint(TreeNode *root)
{
    if (root->left)
    {
        cout << "      (" << root->left->data << ")->" << getNodeType(root->left->data) << endl;// ���������
    }
    if (root->right)
    {
        cout << "      (" << root->right->data << ")->" << getNodeType(root->right->data)<<endl;// ���������
    }
}
// ���νṹ��ӡ���(�����Ҿ���)
/*
1. ������ڵ㲻Ϊ��
2. �����ǰ�ڵ�
3. �ݹ��ӡ������
4. �ݹ��ӡ������
*/
void printTree(TreeNode *root)// ���νṹ��ӡ���
{
    if (root)
    {
        // ��ӡ��ǰ�ڵ�
        cout << "(" << root->data << ")->" << getNodeType(root->data)<<endl;
        //�،�ݔ��������˹��c���ӹ��c���tݔ���ӹ��c
        elementprint(root);
        // �ݹ��ӡ������
        printTree(root->left);
        // �ݹ��ӡ������
        printTree(root->right);
    }
}

#endif