#ifndef TREE_INC
#define TREE_INC

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// Syntax
// ======
// Node: NUM "->" '{' Node ',' Node '}'
//     | NUM
//     |
//     ;
//
// Example
// =======
// 6 -> { 2 -> { 0, 4 -> { 3, 5 } }, 8 -> { 7, 9 } }
//
// TODO: 
// 6 { 2 { 0, 4 { 3, 5 } }, 8 { 7, 9 } }
// 
// Represents:
//
//        _______6______
//       /              \
//    ___2__          ___8__
//   /      \        /      \
//   0      _4       7       9
//         /  \
//         3   5

struct Token {
    enum Type {
        kEof, kNum, kLBracket, kRBracket, kSubNodes, kComma, kUnknown
    };
    Type type;
    int value;

    Token(Type t = kUnknown, int v = 0) : type(t), value(v) {}
};

class Tokenizer {
    const char *s_;
    int i_;

public:
    explicit Tokenizer(const char *s) : s_(s), i_(-1) {}

    Token nextToken() {
        while (1) {
            switch (char c = peek()) {
            case '-': return subNodes();
            case '{': get(); return Token(Token::kLBracket);
            case '}': get(); return Token(Token::kRBracket);
            case ',': get(); return Token(Token::kComma);
            default:
                if (isdigit(c))
                    return integer();
                if (isblank(c)) { consumeBlanks(); break; }
                if (c == '\0') return Token(Token::kEof);
                return Token(Token::kUnknown);
            }
        }
    }    

    Token peekToken() {
        auto i = i_;
        auto tok = nextToken();
        i_ = i;
        return tok;
    }

private:
    char peek() const { return s_[i_+1]; }
    char get() { return s_[++i_]; }

    Token integer() {
        char buf[12];
        int k = 0;
        while (isdigit(peek()))
            buf[k++] = get();
        buf[k] = '\0';

        return Token(Token::kNum, atoi(buf));
    }

    Token subNodes() {
        assert(get() == '-');
        assert(get() == '>');
        return Token(Token::kSubNodes);
    }

    void consumeBlanks() {
        while (isblank(peek())) get();
    } 
};


class Parser {
    Tokenizer tokenizer_;

    Token next() { return tokenizer_.nextToken(); }
    Token peek() { return tokenizer_.peekToken(); }
public:
    explicit Parser(Tokenizer tokenizer) : tokenizer_(tokenizer) {}

    TreeNode *parseNode() {
        auto tok = next();
        if (tok.type != Token::kNum)
            std::cerr << "Expected number but got " << tok.type << '\n';
        assert(tok.type == Token::kNum);
        auto node = new TreeNode(tok.value);

        switch (peek().type) {
        case Token::kEof: 
        case Token::kComma:
        case Token::kRBracket: break; 
        case Token::kSubNodes: {
            next();
            assert(next().type == Token::kLBracket);
            auto left = parseNode();
            assert(next().type == Token::kComma);
            auto right = parseNode();
            assert(next().type == Token::kRBracket);
            node->left = left;
            node->right = right;
            break;
        }
        default:
            std::cerr << "Un-expected token: " << tok.type << '\n';
            assert(0 && "Un-expected token!");
            break;
        }

        std::cout << tok.value << '\n';
        return node;
    }
};

#endif
