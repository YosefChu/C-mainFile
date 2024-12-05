#ifndef USESUFFIXTOBULIDABRANYTREE_H
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
// 定义二叉树节点
/*
0. 叶子节点
1. Concatenation
2. Union
3. Kleene 闭包
*/
class TreeNode// 定义二叉树节点
{
public:
    char data;// 数据
    TreeNode *left;  // 左子树
    TreeNode *right; // 右子树
    TreeNode(char _data)// 构造函数
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
};
// 用后缀表达式构建二叉树
/*
1. 遍历字符串
2. 如果是字母，压入栈中
3. 如果是*，弹出栈顶元素，作为右子树，构建一个新的节点，作为根节点，栈顶元素作为左子树，压入栈中
4. 如果是|，弹出栈顶元素，作为右子树，弹出栈顶元素，作为左子树，构建一个新的节点，作为根节点，压入栈中
5. 如果是-，弹出栈顶元素，作为右子树，弹出栈顶元素，作为左子树，构建一个新的节点，作为根节点，压入栈中
*/
TreeNode *buildTreeFromPostfix(const string str)// 用后缀表达式构建二叉树
{
    int length = str.size();// 字符串的长度
    stack<TreeNode *> letter;// 字母栈
    for (int i = 0; i < length; i++)// 遍历字符串
    {
        TreeNode *node = new TreeNode(str[i]);// 新建一个节点
        if (isalpha(str[i]))// 如果是字母
        {
            letter.push(node);// 压入栈中
        }
        else if (str[i] == '*')// 如果是闭包符号
        {
            TreeNode *root = new TreeNode('*');// 新建一个节点
            root->right = letter.top();// 弹出栈顶元素，作为右子树
            letter.pop();// 弹出栈顶元素
            letter.push(root);// 压入栈中
        }
        else if (str[i] == '|')// 如果是或符号
        {
            TreeNode *root = new TreeNode('|');// 新建一个节点
            root->right = letter.top();// 弹出栈顶元素，作为右子树
            letter.pop();// 弹出栈顶元素
            root->left = letter.top();// 弹出栈顶元素，作为左子树
            letter.pop();// 弹出栈顶元素
            letter.push(root);// 压入栈中
        }
        else if (str[i] == '-')// 如果是连接符号
        {
            TreeNode *root = new TreeNode('-');// 新建一个节点
            root->right = letter.top();// 弹出栈顶元素，作为右子树
            letter.pop();// 弹出栈顶元素
            root->left = letter.top();// 弹出栈顶元素，作为左子树
            letter.pop();// 弹出栈顶元素
            letter.push(root);// 压入栈中
        }
    }
    return letter.top();// 返回栈顶元素
}
// 中序遍历二叉树
/*
1. 如果根节点不为空
2. 递归遍历左子树
3. 输出根节点
4. 递归遍历右子树
5.输出根节点
*/
void inorderTraversal(TreeNode *root)// 中序遍历二叉树
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
// 获取节点类型
/*
0. 叶子节点
1. Concatenation
2. Union
3. Kleene 闭包
-1. 未知类型
*/
int getNodeType(char data)
{
    if (isalpha(data))
        return 0; // 叶子节点
    if (data == '-')
        return 1; // Concatenation
    if (data == '|')
        return 2; // Union
    if (data == '*')
        return 3; // Kleene 闭包
    return -1;    // 未知类型
}
//重寫輸出，如果此節點有子節點，則輸出子節點
/*
1. 如果左子树不为空，输出左子树
2. 如果右子树不为空，输出右子树
*/
void elementprint(TreeNode *root)
{
    if (root->left)
    {
        cout << "      (" << root->left->data << ")->" << getNodeType(root->left->data) << endl;// 输出左子树
    }
    if (root->right)
    {
        cout << "      (" << root->right->data << ")->" << getNodeType(root->right->data)<<endl;// 输出右子树
    }
}
// 树形结构打印输出(根左右編列)
/*
1. 如果根节点不为空
2. 输出当前节点
3. 递归打印左子树
4. 递归打印右子树
*/
void printTree(TreeNode *root)// 树形结构打印输出
{
    if (root)
    {
        // 打印当前节点
        cout << "(" << root->data << ")->" << getNodeType(root->data)<<endl;
        //重寫輸出，如果此節點有子節點，則輸出子節點
        elementprint(root);
        // 递归打印左子树
        printTree(root->left);
        // 递归打印右子树
        printTree(root->right);
    }
}

#endif