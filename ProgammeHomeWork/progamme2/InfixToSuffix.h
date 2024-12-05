#ifndef INFIXTOSUFFIX_H
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 检查是否是运算符
bool isOperator(char str)
{
    return str == '*' || str == '|' || str == '(' || str == ')' || str == '-';
}

// 获取运算符的优先级
int getPriority(char op)
{
    // 优先级定义如下：'(' > '*' > '|' > '-'
    if (op == '|') // 或
        return 1;
    if (op == '*') // 闭包
        return 3;
    if (op == '(' || op == ')') // 括号
        return 4;
    if (op == '-') // 连接
        return 2;
}
// 綁斷輸入合法不合法
/*
1. 不能有空括号
2. 不能有连续的闭包符号
3. 不能有连续的或符号
4. 不能以或符号开头
5. 不能以或符号结尾
*/
void Determining_The_Legitimacy_Of_An_Input(string &str, bool &_bool) // 判断输入的合法性，兩個參數，一個是字符串，一個是bool值
{
    int lenght = str.size();         // 字符串的长度
    int left_par = 0;                // 左括号的个数
    int right_par = 0;               // 右括号的个数
    for (int i = 0; i < lenght; i++) // 遍历字符串
    {
        if (str[i] == '(') // 如果是左括号
        {
            left_par++;            // 左括号的个数加一
            if (str[i + 1] == ')') // 如果左括号后面是右括号
            {
                cout << "Error: 空括号" << endl; // 输出错误信息
                _bool = false;                   //
            }
        }
        else if (str[i] == ')') // 如果是右括号
        {
            right_par++; // 右括号的个数加一
        }
        else if (str[i] == '*') // 如果是闭包符号
        {
            if (i == 0) // 如果闭包符号是第一个字符
            {
                cout << "Error: * 不能是第一个字符" << endl; // 输出错误信息
            }
            if (str[i] == '*' && (str[i - 1] == '(' || str[i - 1] == '|')) // 如果闭包符号前面是左括号或者是或符号
            {
                cout << "Error: *不可以在這符號後面" << str[i - 1] << endl; // 输出错误信息
                _bool = false;
            }
        }
        else if (str[i] == '|') // 如果是或符号
        {
            if (i == 0) // 如果是第一个字符
            {
                cout << "Error: | 不可以是第一個符號" << endl; // 输出错误信息
                _bool = false;
            }
            if (i == lenght - 1)
            {
                cout << "Error: | 不可以是最後一個符號" << endl; // 输出错误信息
                _bool = false;
            }
            if (str[i - 1] == '(' || str[i - 1] == '|') // 如果或符号前面是左括号或者是或符号
            {
                cout << "Error: | 不可以在這符號後面 " << str[i - 1] << endl; // 输出错误信息
                _bool = false;
            }
            if (str[i + 1] == ')') // 如果或符号后面是右括号
            {
                cout << "Error: | 不可以在此符號前面 " << str[i + 1] << endl; // 输出错误信息
                _bool = false;
            }
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') // 如果是大写字母
        {
        }
        else if (str[i] >= 'a' && str[i] <= 'z') // 如果是小写字母
        {
        }
        else // 如果是其他字符
            cout << "Error: 无效字符" << endl;// 输出错误信息
        _bool = false;// 为false
    }
    _bool = true;// 为true，
}
/*
基于上述定义，正则表达式 a | b | c 可以理解为 ( a | b) | c或a | (b | c),  abc可以理解为 (ab) c或 a(bc), (a*)* = a.
*/
// 補全隱含的連接符
/**
 * 1. 如果前一个字符是字母，后一个字符也是字母，插入一个连接符
 * 2. 如果前一个字符是字母，当前字符是闭包符号，后一个字符也是字母，插入一个连接符
 * 3. 如果当前字符是闭包符号，后一个字符是或符号，返回
 * 4. 如果当前字符是闭包符号，后一个字符是字母，插入一个连接符
 * 5. 如果前一个字符是字母，当前字符是左括号，插入一个连接符
 * 6. 如果当前字符是右括号，后一个字符是字母，插入一个连接符
 * 7. 如果当前字符是闭包符号，后一个字符是左括号，插入一个连接符
 */
void complete(string &infix)
{
    int length = infix.size();// 字符串的长度
    for (int i = 0; i < length; i++)
    {
        if (isalpha(infix[i]) && isalpha(infix[i + 1]))// 如果前一个字符是字母，后一个字符也是字母
        {
            infix.insert(i + 1, "-");// 在后一个字符前面插入一个连接符
            i = 0;// 从头开始遍历
            length++;// 长度加一
            // cout << infix<<endl;
        }
        if (isalpha(infix[i - 1]) && infix[i] == '*' && isalpha(infix[i + 1]))// 如果前一个字符是字母，当前字符是闭包符号，后一个字符也是字母
        {
            infix.insert(i + 1, "-");// 在后一个字符前面插入一个连接符
            i = 0;// 从头开始遍历
            length++;// 长度加一
        }
        if (infix[i] == '*' && infix[i + 1] == '|')// 如果当前字符是闭包符号，后一个字符是或符号
        {
            return;// 返回
        }
        if (infix[i] == '*' && isalpha(infix[i + 1]))// 如果当前字符是闭包符号，后一个字符是字母
        {
            infix.insert(i + 1, "-");// 在后一个字符前面插入一个连接符
            i = 0;// 从头开始遍历
            length++;// 长度加一
        }
        if (isalpha(infix[i]) && infix[i + 1] == '(')// 如果前一个字符是字母，当前字符是左括号
        {
            infix.insert(i + 1, "-");// 在后一个字符前面插入一个连接符
            i = 0;// 从头开始遍历
            length++;// 长度加一
        }
        if (infix[i] == ')' && isalpha(infix[i + 1]))// 如果当前字符是右括号，后一个字符是字母
        {
            infix.insert(i + 1, "-");// 在后一个字符前面插入一个连接符
            i = 0;// 从头开始遍历
            length++;// 长度加一
        }
        if (infix[i] == '*' && infix[i + 1] == '(')// 如果当前字符是闭包符号，后一个字符是左括号
        {
            infix.insert(i + 1, "-");// 在后一个字符前面插入一个连接符
            i = 0;// 从头开始遍历
            length++;// 长度加一
        }
    }
}
// 将中缀表达式转换为后缀表达式
/*
1. 如果是操作数，直接添加到后缀表达式
2. 如果是左括号，压入栈中
3. 如果是右括号，弹出栈顶运算符直到遇到左括号
4. 如果是运算符，弹出栈顶优先级高于或等于当前运算符的所有运算符
5. 压入当前运算符
6. 最后弹出栈中所有运算符
*/
string InfixToSuffix(string infix)
{
    stack<char> operators;// 运算符栈
    string postfix;// 后缀表达式
    for (char c : infix)// 遍历中缀表达式
    {
        if (isspace(c))
            continue; // 跳过空格
        if (isalpha(c))// 如果是操作数
        {
            // 如果是操作数，直接添加到后缀表达式
            postfix += c;
        }
        else if (c == '(')// 如果是左括号
        {
            // 如果是左括号，压入栈中
            operators.push(c);
        }
        else if (c == ')')// 如果是右括号，弹出栈顶运算符直到遇到左括号
        {
            // 如果是右括号，弹出栈顶运算符直到遇到左括号
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // 弹出左括号
        }
        else if (isOperator(c))// 如果是运算符,弹出栈顶优先级高于或等于当前运算符的所有运算符
        {
            if (c == '*')// 如果是闭包符号
            {
                postfix += c;// 直接添加到后缀表达式
                continue;
            }
            if (operators.empty())// 如果栈为空
            {
                operators.push(c);// 压入当前运算符
            }
            else
            {
                // 如果是运算符，弹出栈顶优先级高于或等于当前运算符的所有运算符
                while (!operators.empty() && getPriority(operators.top()) >= getPriority(c) && operators.top() != '(')// 如果栈不为空，栈顶优先级高于或等于当前运算符，栈顶不是左括号
                {
                    postfix += operators.top();// 添加到后缀表达式
                    operators.pop();// 弹出栈顶
                }
                operators.push(c); // 压入当前运算符
            }
        }
    }
    // cout << postfix << endl;
    while (!operators.empty())// 最后弹出栈中所有运算符
    {
        // cout << postfix;
        postfix += operators.top();// 添加到后缀表达式
        operators.pop();// 弹出栈顶
    }
    return postfix;// 返回后缀表达式
}
// 将后缀表达式刪除多出來的雙*號，( (a*)* = a)如a**->a
/*
1. 遍历字符串
2. 如果当前字符是*，后一个字符也是*，删除后一个字符
3. 重复上述步骤
*/
void delete_star(string &suffix)// 删除多余的双*号
{
    for (int i = 0; i < suffix.size(); i++)
    {
        if (suffix[i] == '*' && suffix[i + 1] == '*')// 如果当前字符是*，后一个字符也是*
        {
            suffix.erase(i, 2);// 删除后一个字符
            i = 0;// 从头开始遍历
        }
    }
    // cout << suffix << endl;
}
#endif