/**
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/

/**
 * 解法：
 * 转化为逆波兰式，在转换过程中，每当有operator要输出时，就地计算。
 * 
 * TODO:
 * 效率差于大部分C++答案，可能是因为用了stringstream什么的，稍后
 */

#include <stack>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void calc_helper(stack<int> &oprands, stack<char> &operators) {
    char op = operators.top();
    operators.pop();
    int oprand1 = oprands.top();
    oprands.pop();
    int oprand2 = oprands.top();
    oprands.pop();

    int result = 0;
    switch (op) {
    case '+':
        result = oprand2 + oprand1;
        break;
    case '-':
        result = oprand2 - oprand1;  // 注意操作数顺序
        break;
    }
    oprands.push(result);
}

int calculate(string s) {
    stringstream buf;
    stack<int> oprands;
    stack<char> operators;

    int i = 0;
    while (i < s.size()) {
        if (isdigit(s[i])) {
            while (isdigit(s[i])) {
                buf << s[i++];
            }
            oprands.push(atoi(buf.str().data()));
            buf.str("");
            --i;
        } else if (s[i] == '+' || s[i] == '-') {
            while (!operators.empty() && operators.top() != '(') {
                calc_helper(oprands, operators);
            }
            operators.push(s[i]);
        } else if (s[i] == '(') {
            operators.push(s[i]);
        } else if (s[i] == ')') {
            while (1) {
                if (operators.top() == '(') {
                    operators.pop();
                    break;
                }
                calc_helper(oprands, operators);
            }
        }
        ++i;
    }

    while (!operators.empty()) {
        calc_helper(oprands, operators);
    }

    return oprands.top();
}

int main(int argc, char **argv) {
    cout << calculate(argv[1]) << '\n';
    return 0;
}
