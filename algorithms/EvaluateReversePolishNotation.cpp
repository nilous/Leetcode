/**
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include <assert.h>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int evalRPN(vector<string> &tokens) {
    stack<int> oprands;

    for (auto tok : tokens) {
        if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
            int oprand1 = oprands.top();
            oprands.pop();
            int oprand2 = oprands.top();
            oprands.pop();
            int result = 0;
            switch (tok[0]) {
            case '+': result = oprand2 + oprand1; break;
            case '-': result = oprand2 - oprand1; break;
            case '*': result = oprand2 * oprand1; break;
            case '/': result = oprand2 / oprand1; break;
            }
            oprands.push(result);
        } else {
            oprands.push(atoi(tok.data()));
        }
    }
    assert(oprands.size() == 1);
    return oprands.top();
}

struct TestCase {
    vector<string> rpn;
    int expected;
} cases[] = {
    { { "2", "1", "+", "3", "*" }, 9 },
    { { "4", "13", "5", "/", "+" }, 6 }
};

int main(int argc, char **argv) {
    for (auto c : cases)
        assert(evalRPN(c.rpn) == c.expected);
    return 0;
}
