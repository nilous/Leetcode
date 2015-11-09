/**
 Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
*/

/**
 * 与Basic Calculator的不同在于操作符有优先级的差异，
 * 参考逆波兰式的处理方式：
 * 当一个操作符需要入栈时，须将栈顶所有优先级**不小于**它的操作符出栈。
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
    case '*':
        result = oprand2 * oprand1;
        break;
    case '/':
        result = oprand2 / oprand1;
        break;
    }
    oprands.push(result);
}

int op_compare(char op1, char op2) {
#define OP_PRIORITY(op) (((op) == '+' || (op) == '-') ? 0 : 1)
    if (OP_PRIORITY(op1) == OP_PRIORITY(op2)) return 0;
    return OP_PRIORITY(op1) < OP_PRIORITY(op2) ? -1 : 1;
#undef OP_PRIORITY
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
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            while (!operators.empty() && op_compare(operators.top(), s[i]) != -1) {
                calc_helper(oprands, operators);
            }
            operators.push(s[i]);
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
